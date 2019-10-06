main = do
    [n,i] <- map read . words <$> getLine
    print $ n + 1 - i