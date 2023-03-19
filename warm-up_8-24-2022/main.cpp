#include <iostream>

using namespace std;

// mF 24 Aug 22
// Project: WarmUp24Aug
// File: main.cpp
// Warm up coding activity for CIT-66, Fall 2022

int main()
{
    int num1 = 0;
    int num2 = 0;

    cout << "\nPlease enter two integers in the range of 1 to 100, lowest number first (ex. enter 7 at the first prompt, then enter 42 at the second prompt): ";
    cout << "\n\nFirst integer: ";
    cin >> num1;
    cout << "\nSecond integer: ";
    cin >> num2;

    for (int i=1; i<=num1; i++)
    {
        cout << "\n\n\n  Outer loop: num1 = " << num1 << "   num2 = " << num2 << "   i = " << i << "\n\n";
        for (int j=1; j<=num2; j++)
        {
            cout << "\n  Inner loop: num1 = " << num1 << "   num2 = " << num2 << "   j = " << j;
        }
    }
    return 0;
}
