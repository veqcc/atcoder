main = do
    [n,a,b] <- map read . words <$> getLine
    print $ sum [k | k <- [1 .. n], evaluate k >= a, evaluate k <= b]

evaluate k = sum [read [c] | c <- show k]