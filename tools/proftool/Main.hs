module Main where

import System (getArgs)
import CallgrindParser
import Analysis


main = do
  (h:_) <- getArgs
  runCPUProf h
