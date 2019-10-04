main = getLine >>= print . length . filter (== '1')
