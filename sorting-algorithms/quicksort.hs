qsort :: Ord a => [a] -> [a]
qsort []     = []
qsort (x:xs) = qsort lesser ++ [x] ++ qsort greater
    where
        lesser  = filter (< x) xs
        greater = filter (>= x) xs

main :: IO ()
main = do
  print $ quicksort $ reverse [1..10]