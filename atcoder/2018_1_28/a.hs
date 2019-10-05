main = do
    x <- readLn
    a <- readLn
    b <- readLn
    print $ mod (x - a) b
    