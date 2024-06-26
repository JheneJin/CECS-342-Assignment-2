# Class object type for People
class People:
  
  def __init__(self, personName, personAge ):
    self.name = personName
    self.age = personAge

  def __str__(self):
    return self.name + ", " + str(self.age)

  # sorts by age in descending order and compares name if age is equal as default type comarison
  def __lt__(self, person):
    # If the age is less return false, else true
    if (self.age < person.age):
      return False
    # If they are equal, switch to comparing the name
    elif (self.age == person.age):
      # If the name is less return true, else false
      if (self.name < person.name):
        return True
      return False
    return True


# Comparison function that only compares the name of an object as long as it has the name attribute
def compareNameOnly(object):
  return object.name


def main():
  # Array of people
  personArray = [People("Hal", 20), People("Susann", 31), People("Dwight", 19), People("Kassandra", 21), People("Lawrence", 25), People("Cindy", 22), People("Cory", 27), People("Mac", 19), People("Romana", 27), People("Doretha", 32), People("Danna", 20), People("Zara", 23), People("Rosalyn", 26), People("Risa", 24), People("Benny", 28), People("Juan", 33), People("Natalie", 25)]

  # Array of numbers
  numberArray = [645.41, 37.59, 76.41, 5.31, -34.23, 1.11, 1.10, 23.46, 635.47, -876.32, 467.83, 62.25]
  
  print("--------------------------------------------")
  print("Sorting age in descending order, and if equal then by name in lexicographical order")
  print("-------------")
  print("Before:")
  print("-------------")
  for i in range(0, len(personArray)):
      print(personArray[i], end=";\n")
  print("-------------")
  print("After:")
  print("-------------")
  # Uses generic sort
  personArray = sorted(personArray)
  for i in range(0, len(personArray)):
    print(personArray[i], end=";\n")
  print("--------------------------------------------")
  
  print("\n\n\n")
  
  print("--------------------------------------------") 
  print("Sorting name in lexicographical order")
  print("-------------")
  print("Before:")
  print("-------------")
  for i in range(0, len(personArray)):
      print(personArray[i], end=";\n")
  print("-------------")
  print("After:")
  print("-------------")
  # Uses generic sort, and compares the array
  # by using the compareNameOnly function that's passed in
  # as the key
  personArray = sorted(personArray, key=compareNameOnly)
  for i in range(0, len(personArray)):
    print(personArray[i], end=";\n")
  print("--------------------------------------------")
  
  print("\n\n\n")
  
  print("--------------------------------------------")
  print("Sorting numbers ascending by numerical value")
  print("-------------")
  print("Before:")
  print("-------------")
  for i in range(0, len(numberArray)):
      print(numberArray[i], end="\n")
  print("-------------")
  print("After:")
  print("-------------")
  # Uses generic sort
  numberArray = sorted(numberArray)
  for i in range(0, len(numberArray)):
    print(numberArray[i], end="\n")
  print("--------------------------------------------")

main()
