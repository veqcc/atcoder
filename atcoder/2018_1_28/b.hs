main = do
    a <- readLn
    b <- readLn
    c <- readLn
    x <- readLn
    print $ length [() | u <- [0 .. a], v <- [0 .. b], w <- [0 .. c], 500 * u + 100 * v + 50 * w == x]