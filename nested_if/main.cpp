#include <iostream>

using namespace std;

int main()
{
    // Initialize variables

    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    int largest = 0;

    // Get 3 values from user input

    cout << "\nEnter number 1: ";
    cin >> num1;

    cout << "\nEnter number 2: ";
    cin >> num2;

    cout << "\nEnter number 3: ";
    cin >> num3;

    cout << "\nYou entered: " << endl << "    num1 = " << num1 <<
                                 endl << "    num2 = " << num2 <<
                                 endl << "    num3 = " << num3 << "\n\n";

    // Test values with nested if statements and put result in variable 'largest'

    if(num1 > num2)
    {
        if(num1 > num3)
        {
            largest = num1;
        }
        else
        {
            largest = num3;
        }
    }
    else
    {
        if(num2 > num3)
        {
            largest = num2;
        }
        else
        {
            largest = num3;
        }

    }


    // Output the result

    cout << "Result of value test: " << largest << " is largest" << endl;

    return 0;
}
