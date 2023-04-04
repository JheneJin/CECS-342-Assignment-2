using System;
using System.Linq;

class Program {
  public static void Main (string[] args) {
    Console.WriteLine ("Hello Assignment 2\n");
    
    Console.WriteLine("persons BEFORE sorting");
    Person [] persons = {new Person("Hal", 20), new Person("Susann", 31), new Person("Dwight", 19), new Person("Kassandra", 21), new Person("Lawrence", 25), new Person("Cindy", 22), new Person("Cory", 27), new Person("Mac", 19), new Person("Romana", 27), new Person("Doretha", 32), new Person("Danna", 20), new Person("Zara", 23), new Person("Rosalyn", 26), new Person("Risa", 24), new Person("Benny", 28), new Person("Juan", 33), new Person("Natalie", 25)};
    
    foreach (Person p in persons){
      Console.WriteLine(p.name + ", " + p.age);
    }

    Console.WriteLine("\npersons AFTER sorting");
    persons = persons.OrderBy(p => p).ToArray();
    //Array.Sort(persons);
    foreach (Person p in persons){
      Console.WriteLine(p.name + ", " + p.age);
    }

    
    Console.WriteLine ("\n\nnumbers BEFORE sorting");
    double[] numbers = {645.41, 37.59, 76.41, 5.31, -34.23, 1.11, 1.10, 23.46, 635.47, -876.32, 467.83, 62.25};
    foreach (double i in numbers){
      Console.Write(i + " ");
    }

    //numbers = numbers.OrderByDescending(x =>x).ToArray();
    Array.Sort(numbers);
    Console.WriteLine ("\nnumbers AFTER sorting");
    foreach (double i in numbers){
      Console.Write(i + " ");
    }
  }
}

public class Person : IComparable<Person> {
  public int age;
  public String name;

  public Person(String n, int a){
    age = a;
    name = n;
  }

   public int CompareTo(Person that)
    {
        if (this.age >  that.age) return -1;
        if (this.age == that.age) return this.name.CompareTo(that.name);;
        return 1;
    }
  
}