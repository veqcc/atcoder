import Control.Monad
import Data.List

main = do
    n <- readLn
    d <- replicateM n readLn
    print $ length $ group $ sort (d :: [Int])