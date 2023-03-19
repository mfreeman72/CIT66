#include <iostream>

using namespace std;

int main()
{
    cout << "Warm Up 22 Aug 22" << endl;

    // Control structures

    int num1 = 0;
    int num2 = 0;
    int num3 = 0;

    cout << "\n Enter your first number: ";
    cin >> num1;

    cout << "\n Enter your second number: ";
    cin >> num2;

    if (num1 > num2)
    {
        cout << "\n The number " << num1 << " is larger than " << num2 << "\n ";
    }
    else
    {
        cout << "\n The number " << num2 << " is larger than " << num1 << "\n ";
    }

    for (int i=0; i<100; i++)
    {
        cout << "\n The loop control variable, i, is " << i;
    }

    // Create variable, initialize, create while loop, increment variable, loop until target value is reached

    int myVariable = 0;

    while (myVariable < 10)
    {
        cout << "\nHere's my variable value: " << myVariable;
        myVariable++;
    }

    cout << "\n The loop ended with a loop variable value of " << myVariable;

    // Infinite loop

    while (myVariable > 0)
    {
        myVariable++;
        cout << "\nHere's my variable value: " << myVariable;
    }

    return 0;
}
