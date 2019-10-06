main = do
    n <- readLn
    print $ f n 111

f n c
    | n > c = f n $ c + 111
    | otherwise = c