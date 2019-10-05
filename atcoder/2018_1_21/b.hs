main = do
    [a, b] <- words <$> getLine
    let n = read (a ++ b) :: Int
    let s = round $ sqrt (realToFrac n)
    putStrLn $ if (s ^ 2 == n) then "Yes" else "No"