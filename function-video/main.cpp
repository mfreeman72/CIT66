#include <iostream>

using namespace std;

void introduceMe(string, string city, int=0);

int main()
{
    string name;
    string city;
    int age;

    cout << "Name: ";
    cin >> name;
    cout << "City: ";
    cin >> city;
    cout << "Age: ";
    cin >> age;

    introduceMe(name, city, age);

//    introduceMe("Mike", "Fresno", 49);
//    introduceMe("Bob", "LA");
    return 0;
}

void introduceMe(string name, string city, int age)
{
    cout << "\n\nMy name is " << name << endl;
    cout << "I am from " << city << endl;
    if(age!=0)
        cout << "I am " << age << " years old" << endl;
}
