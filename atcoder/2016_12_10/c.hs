main = do
    s <- getLine
    putStrLn $ if analyze (reverse s) then "YES" else "NO"

analyze "" = True
analyze ('m':'a':'e':'r':'d':k) = analyze k
analyze ('r':'e':'m':'a':'e':'r':'d':k) = analyze k
analyze ('e':'s':'a':'r':'e':k) = analyze k
analyze ('r':'e':'s':'a':'r':'e':k) = analyze k
analyze _ = False