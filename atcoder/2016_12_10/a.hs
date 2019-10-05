main = do
    c <- getChar
    putStrLn $ if elem c "aiueo" then "vowel" else "consonant"