main = do
    a:b:c:d:_ <- map read . words <$> getLine
    putStrLn $ case compare (a + b) (c + d) of
        GT -> "Left"
        LT -> "Right"
        EQ -> "Balanced"