module CPUProfParser where
import qualified Data.ByteString.Char8 as BS
import qualified Data.ByteString.Lazy.Char8 as BSL
import Data.Binary.Get
import qualified Data.IntMap as IM
import qualified Data.Attoparsec.Char8 as AP
import Control.Applicative ((<|>))
import Control.Monad
import Data.Maybe
import Debug.Trace
import Utils

data Frame = Frame {frameFunc :: BS.ByteString, frameFile :: BS.ByteString,
  frameLine :: Int}
  deriving Show
unknownFrame = Frame BS.empty BS.empty 0

dropLine bs = BS.drop ((fromJust $ BS.elemIndex '\n' bs) + 1) bs

runParseSyms s = loop (AP.parse parseSyms s)
  where
  loop (AP.Done _ ps) = ps
  loop (AP.Partial r) = loop (r BS.empty)

splitSymbols bs = (syms, prof)
  where
  (s, p) = BS.breakSubstring (BS.pack "--- profile\n") bs
  ps = runParseSyms s
  syms = foldl (\m (pc, frm) -> IM.insert pc frm m) IM.empty ps
  prof = dropLine p

parseSyms = do
  junkLine
  junkLine
  frames <- AP.many parseFrame
  return frames

parseFrame = do
  AP.string (BS.pack "0x")
  pc <- AP.hexadecimal
  AP.space
  fl <- AP.takeTill (==':')
  AP.char ':'
  lnum <- AP.decimal
  AP.space
  fn <- AP.takeWhile (/='\n')
  AP.char8 '\n'
  return $ (pc, Frame fn (BS.pack . normalizePath . BS.unpack $ fl) lnum)

testParseFrame = AP.parseTest parseFrame (BS.pack "0x0000000024dbc6c3 type_variant.h:376 HPHP::f_render_inlinecomment_array(HPHP::Variant const&, HPHP::Variant const&)<0000000024dbc4a0>\n")

junkLine = do
  AP.skipWhile (/='\n')
  AP.char8 '\n'

getTraces = do
  samps <- getWord64le
  frameCt <- getWord64le
  frames <- replicateM (fromIntegral frameCt) getWord64le
  emp <- isEmpty
  if emp || head frames == 0
    then return []
    else do
      rest <- getTraces
      return $ (frames, samps):rest

getHeader = do
  hc <- getWord64le
  hs <- getWord64le
  fv <- getWord64le
  per <- getWord64le
  getWord64le --padding
  return (hc, hs, fv, per)

translateStack frames syms =
  map (\f -> IM.findWithDefault unknownFrame (fromIntegral f) syms)
    frames

getProf syms = runGet $ do
  h <- getHeader
  br <- bytesRead
  ts <- getTraces
  return $ (h, ts, map (\(frms, ct) -> (translateStack frms syms, ct)) ts)

parseCPUProf f = do
  bs <- BS.readFile f
  let (syms, prof) = splitSymbols bs
  let (h, ts, p) = getProf syms (BSL.fromChunks [prof])
  return p

testFile = "/home/iproctor/local2/callgrind/home.raw"
test = do
  bs <- BS.readFile testFile
  let (syms, prof) = splitSymbols bs
  let (h, ts, p) = getProf syms (BSL.fromChunks [prof])
  print p
