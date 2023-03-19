#include <iostream>

using namespace std;

// mF 8/15/22
// main.cpp

int main()
{
    // Declare variables
    int num1;
    int num2;
    int sumOfInput;

    string usersName;

    // Get the user's name
    cout << "Enter your name: ";
    cin >> usersName;

    // Get numbers from user input
    cout << "\nEnter the first number: ";
    cin >> num1;
    cout << "\nEnter the second number: ";
    cin >> num2;

    // Find the sum
    sumOfInput = num1 + num2;

    // Output the sum to the user
    cout << "\n\nHi, " << usersName << "! The sum of your numbers is " << sumOfInput << ".";

    // Extra stuff based on in-class discussion (not part of warm-up):
    // For-loop counting
    cout << "\n\nCounting to " << sumOfInput << ":" << endl;
    for (int i=0 ; i<sumOfInput; i++)
    {
        cout << i + 1 << endl;
    }
    return 0;
}
