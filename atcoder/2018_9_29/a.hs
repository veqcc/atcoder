main = do
    n <- getLine
    putStrLn $ f n

f ('1' : xn) = '9' : (f xn)
f ('9' : xn) = '1' : (f xn)
f x = x