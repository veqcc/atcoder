main = do
    [n,y] <- map read . words <$> getLine
    let ans = [ [a, b, c] | a <- [0..n],
                            b <- [0..n-a],
                            let c = n - a - b,
                            10000 * a + 5000 * b + 1000 * c == y ] ++ [replicate 3 (-1)]
    putStrLn .unwords . map show . head $ ans
