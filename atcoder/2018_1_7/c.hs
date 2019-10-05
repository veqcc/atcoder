main = do
    [n,y] <- map read . words <$> getLine
    let ans = [[a, b, c] | a <- [0 .. n],
                           b <- [0 .. n-a],
                           let c = n - a - b,
                           10000 * a + 5000 * b + 1000 * c == y ]
    putStrLn $ unwords $ map show $ if null ans then [-1, -1, -1] else head ans
