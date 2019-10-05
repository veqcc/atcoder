main = do
   getLine
   ls <- lines <$> getContents
   mapM putStrLn $ duplicate ls

duplicate :: [String] -> [String]
duplicate [] = []
duplicate (x : xs) = x : x : duplicate xs