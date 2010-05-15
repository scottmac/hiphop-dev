module Analysis where

import Text.Regex.TDFA
import CallgrindParser
import CPUProfParser
import Text.Printf
import Data.Maybe
import qualified Data.ByteString.Char8 as BS
import qualified Data.Map as M
import qualified Data.List as L
-- callgrind
outputCGReport d = mapM_ outputPartReport d

outputPartReport p = do
  let Part _ d = p
  let leaves = getLeaves d
  let totalCost = sumCosts leaves
  let invokeCost = sumCosts . filterFnRegex ".*invoke.*" $ leaves
  let nonGenCost = sumCosts . filterOutFlRegex "[0-9][0-9][0-9].*\\.cpp" $ leaves
  print invokeCost
  print nonGenCost
  print totalCost

leafCost (Leaf _ _ (_:c:_)) = c
leafFn (Leaf _ f _ ) = f
leafFl (Leaf f _ _) = f
isLeaf (Leaf _ _ _) = True
isLeaf _ = False

assocCalls (Assoc _ _ _ _ (c:_) _) = c

sumCosts = foldl (\c l -> leafCost l + c) 0
getLeaves = filter isLeaf
filterFnRegex pat = filter (\l -> leafFn l =~ pat)
filterOutFnRegex pat = filter (\l -> not $ leafFn l =~ pat)
filterFlRegex pat = filter (\l -> leafFl l =~ pat)
filterOutFlRegex pat = filter (\l -> not $ leafFl l =~ pat)


-- raw pprof

sumTotalCost = foldl (\s (_, c) -> c + s) 0
sumFilteredCosts filt = foldl (\s (frms, c) -> if filt frms then c + s else s) 0

testTop p (h:t) = p h

testUpToUser t (h:tl) | isInUser h = False
                      | t h = True
                      | otherwise = testUpToUser t tl
testUpToUser _ _ = False

inStack t (h:tl) | t h = True
                 | otherwise = inStack t tl
inStack _ _ = False

isInExt f = frameFile f =~ ".*/ext_.*"
isInUser f = frameFile f =~ ".*/[0-9][0-9][0-9].*\\.cpp"

isInvoke f = frameFunc f =~ ".*invoke.*"
isClassMethod f = frameFunc f =~ ".*::o_.*"

isNetwork f = frameFile f =~ "(.*mysql.*)|(.*mcc.*)"

isArray f = frameFile f =~ ".*array.*" &&
  not (frameFile f =~ ".*/type_array.*")
isSmartPtr f = frameFile f =~ ".*/type_.*"

isMalloc f = frameFunc f =~ ".*malloc.*"
isSmartAlloc f = frameFile f =~ ".*/smart_allocator\\..*"
costFilters = [("Ext inclusive", testUpToUser isInExt),
               ("User code", testTop isInUser),
               ("Invokes exclusive", testTop isInvoke),
               ("Class support methods exclusive", testTop isClassMethod),
               ("Mysql/Mcc inclusive", testUpToUser isNetwork),
               ("All array related", testTop isArray),
               ("Smart pointers", testTop isSmartPtr),
               ("malloc", testUpToUser isMalloc),
               ("smart_allocator", inStack isSmartAlloc),
               ("smart_allocator ext", \s -> inStack isSmartAlloc s &&
                 testUpToUser isInExt s),
               ("variant ext", \s -> testTop (\f ->
                 frameFile f =~ ".*/type_variant.*") s &&
                 testUpToUser isInExt s)
               ]

getCostPerc p = map (\f -> (fromIntegral $ sumFilteredCosts f p) / tc)
  where
    tc = fromIntegral $ sumTotalCost p

sumCostByFile p = foldl (\r (f:_,c) -> M.alter (\v -> Just $ (fromMaybe 0 v) + c)
  (BS.unpack . frameFile $ f) r) M.empty p

printCost p total (desc, filt) = printf "%s: %.2f\n" desc
  ((fromIntegral $ sumFilteredCosts filt p :: Double) / total)

costReport p = do
  let total = fromIntegral $ sumTotalCost p
  let thresh = floor $ 0.01 * total
  printf "Total samples: %f\n" total
  mapM_ (printCost p total) costFilters
  printf "Time spent in top files:\n"
  mapM_ (\(fl, cst) -> printf "%s : %d %.2f\n" fl cst
    ((fromIntegral cst) / total))
    (L.takeWhile (\(_,c) -> c > thresh) .
    L.sortBy (\(_,c) (_,c2) -> compare c2 c) .
    M.toList $ sumCostByFile p)

runCPUProf f = do
  p <- parseCPUProf f
  costReport p

