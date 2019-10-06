main = do
    k <- readLn
    print $ (div k 2) * (k - (div k 2))