main = do
    [x,y] <- map read . words <$> getLine
    print $ length $ takeWhile (<= y) [x * (2 ^ i) | i <- [0 ..]]