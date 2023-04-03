#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

//define class type for person
class Person {
    public: 
        string name;
        int age;
};

//override function for Person class to compare ages
bool ageCompare(const Person& a, const Person& b) {
    if (a.age != b.age) {
        return a.age > b.age;
    }
    return a.name < b.name;
}

//override function for Person class to compare names
bool nameCompare(const Person& a, const Person& b) {
    if (a.name != b.name) {
        return a.name < b.name;
    }
    return a.age < b.age;
}

//override function for printing an element from the Person class
ostream &operator<<(ostream &output, const Person &p) {
    output << p.name << ", " << p.age << " ";
    return output;
}

int main() {
    vector <float> arr = {645.41, 37.59, 76.41, 5.31, -34.23, 1.11, 1.10, 23.46, 635.47, -876.32, 467.83, 62.25};
    int length = arr.size();
    // cout << length << endl;
    //use generic sort programming here to sort elements in the array
    sort(arr.begin(), arr.end());
    cout << "Comparing Float Numbers Here" << endl;
    for (int i = 0; i < length; i++) {
        cout << fixed << setprecision(2) << arr[i] << ", ";
    }
    cout << endl;
    cout << endl;

    vector <int> arr2 = {300, 10, 60, 9, 15, 16, 19, 30, 60, 50, 90, 100, 70, 80};
    int length2 = arr.size();
    // cout << length << endl;
    //use generic sort programming here to sort elements in the array
    sort(arr2.begin(), arr2.end());
    cout << "Comparing Int Numbers Here" << endl;
    for (int i = 0; i < length; i++) {
        cout << fixed << setprecision(2) << arr2[i] << ", ";
    }

    cout << endl;
    cout << endl;
    cout << "Comparing Person's Names Here" << endl;
    vector <Person> arr3 = {{"Hal", 20}, {"Susann", 31}, {"Dwight", 19}, {"Kassandra", 21}, {"Lawrence", 25}, {"Cindy", 22}, {"Cory", 27}, {"Mac", 19}, {"Romana", 27}, {"Doretha", 32}, {"Danna", 20}, {"Zara", 23}, {"Rosalyn", 26}, {"Risa", 24}, {"Benny", 28}, {"Juan", 33}, {"Natalie", 25}};
    int length3 = arr3.size();
    // cout << "length 3: "  << length3 << endl;
    //takes third parameter nameCompare to override the function and allows us to sort the person class by name
    sort(arr3.begin(), arr3.end(), nameCompare);
     for (int i = 0; i < length3; i++) {
        cout << arr3[i] << "; ";
    }

    cout << endl;
    cout << endl;
    cout << "Comparing Person's Ages Here" << endl;
    vector <Person> arr4 = {{"Hal", 20}, {"Susann", 31}, {"Dwight", 19}, {"Kassandra", 21}, {"Lawrence", 25}, {"Cindy", 22}, {"Cory", 27}, {"Mac", 19}, {"Romana", 27}, {"Doretha", 32}, {"Danna", 20}, {"Zara", 23}, {"Rosalyn", 26}, {"Risa", 24}, {"Benny", 28}, {"Juan", 33}, {"Natalie", 25}};
    //takes third parameter ageCompare to override the function and allows us to sort the person class by age
    sort(arr4.begin(), arr4.end(), ageCompare);
    int length4 = arr4.size();
    // cout << "length 4: "  << length4 << endl;
    for (int i = 0; i < length4; i++) {
        cout << arr4[i] << "; ";
    }
}
