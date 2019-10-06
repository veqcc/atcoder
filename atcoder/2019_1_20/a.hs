main = do
    [ab, bc, ca] <- map read . words <$> getLine
    print $ div (ab * bc) 2