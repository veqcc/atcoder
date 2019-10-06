import Data.Maybe

main = do
    [x, y] <- map read . words <$> getLine
    print $ fromMaybe (-1) (f x y)

f x y
    | odd y || y < 0 = Nothing
    | odd (abs(x) - div y 2) = Nothing
    | abs(x) > div y 2 = Nothing
    | otherwise = Just (div y 2)