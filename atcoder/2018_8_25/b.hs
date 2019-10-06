import Data.List

main = do
    getLine
    cell <- lines <$> getContents
    putStrLn $ unlines $ transpose $ solve $ transpose $ solve $ cell

solve :: [String] -> [String]
solve l = filter (elem '#') l