module Utils where
import qualified System.FilePath as FP
import qualified Data.List as L

normalizePath p = FP.joinPath . L.reverse . loop 0 . L.reverse . FP.splitPath $ p
  where
  loop n [] = L.replicate n ".."
  loop n ("..":t) = loop (n+1) t
  loop n ("../":t) = loop (n+1) t
  loop n (".":t) = loop n t
  loop n ("./":t) = loop n t
  loop n (h:t) | n > 0 = loop (n-1) t
               | otherwise = h : loop n t
