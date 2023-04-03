import Data.Function
import Data.List

data Person = Person String Int deriving (Show, Eq)

name :: Person -> String
name   (Person n a) = n

age :: Person -> Int
age    (Person n a) = a 

instance Ord Person where
  p <= q = name p <= name q

numbers = [645.41, 37.59, 76.41, 5.31, -34.23, 1.11, 1.10, 23.46, 635.47, -876.32, 467.83, 62.25]
people = [
  Person "Hal" 20,
  Person "Susann" 31,
  Person "Dwight" 19,
  Person "Kassandra" 21,
  Person "Lawrence" 25,
  Person "Cindy" 22,
  Person "Cory" 27,
  Person "Mac" 19,
  Person "Romana" 27,
  Person "Doretha" 32,
  Person "Danna" 20,
  Person "Zara" 23,
  Person "Rosalyn" 26,
  Person "Risa" 24,
  Person "Benny" 28,
  Person "Juan" 33,
  Person "Natalie" 25]

sortedNumbers = sortBy (\a b-> compare a b) numbers
nameSort = sortBy (compare `on` name) people
ageSort = sortBy ((flip compare `on` age) <> (compare `on` name)) people

main :: IO ()
main = do
  putStrLn "Sorted numberical values:"
  print sortedNumbers
  putStrLn "People sorted alphabetically by name:"
  print nameSort
  putStrLn "People sorted first by descending age and then alphabetical names:"
  print ageSort
