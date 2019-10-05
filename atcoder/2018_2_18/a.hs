main = do
    n <- readLn
    a <- readLn
    putStrLn $ if (mod n 500) <= a then "Yes" else "No"