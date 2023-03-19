#include <iostream>

using namespace std;

// Declare functions above main():
int sumOfTwoInts(int num1, int num2);

int sumOfThreeInts(int num1, int num2, int num3);

// Main:
int main()
{
    // Declare and initialize num* variables:
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;

    // Get three numbers from the user:
    cout << "\nEnter number one: ";
    cin >> num1;

    cout << "\nEnter number two: ";
    cin >> num2;

    cout << "\nEnter number three: ";
    cin >> num3;

    // Call the functions -- in this case it's in an output string:
    cout << "\n\nThe sum of the first two numbers is: " << sumOfTwoInts(num1, num2);
    cout << "\n\nThe sum of all three numbers is: " << sumOfThreeInts(num1, num2, num3) << "\n\n";

    return 0;
}

// Define functions below main():
int sumOfTwoInts(int num1, int num2)
{
    return (num1 + num2);
}

int sumOfThreeInts(int num1, int num2, int num3)
{
    return (num1 + num2 + num3);
}
