#include <iostream>

using namespace std;

// Function prototype definition
double areaOfaCircle(double, double);

// Main program
int main()
{
    // Variable declaration section
    double radius = 0;
    char changePi;
    double userDefinedPi = 3.14;
    double circleArea = 0.0;

    // Get circle's radius from user
    cout << "\nPlease enter radius: ";
    cin >> radius;

    // Check to see if user wants a different number for pi other than the default and test input for proper response -- if not y or n, keep asking
    while(changePi != 'y' && changePi != 'n')
    {
        // Get user input
        cout << "\nPi is currently set to 3.14, do you want to change this (y/n)?";
        cin >> changePi;

        // Test response for a y
        if(changePi=='y')
        {
            cout << "\nPlease enter your new value for pi: ";
            cin >> userDefinedPi;
        }
        // Test response for anything other than n
        else if(changePi!='n')
        {
            // Give user feedback about incorrect response
            cout << "\n\nAnswer must be either lower-case y or lowercase n. Please try again.\n\n";
        }
    }

    // Call areaOfaCircle function and store return value in circleArea variable
    circleArea = areaOfaCircle(radius, userDefinedPi);

    // Output the area of the user-defined circle
    cout << "\n\nThe area of your circle is: " << circleArea << endl;

    return 0;
}

// Function definition
double areaOfaCircle(double radius, double pi)
{
    return pi * radius * radius;
}
