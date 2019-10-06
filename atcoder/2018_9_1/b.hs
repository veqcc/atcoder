main = do
   [x1, y1, x2, y2] <- map read . words <$> getLine
   let x = x2 - x1
   let y = y2 - y1
   putStrLn $ unwords $ map show [x2 - y, y2 + x, x1 - y, y1 + x]
