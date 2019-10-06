main = do
    s <- readLn
    print $ f 1 s

f c s
    | s == 4 || s == 2 || s == 1 = c + 3
    | even s = f (c + 1) (div s 2)
    | otherwise = f (c + 1) (3 * s + 1)