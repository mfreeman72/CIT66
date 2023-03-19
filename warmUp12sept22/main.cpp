#include <iostream>
using namespace std;

// mF 9/12/22
// warmUp12sept22.cpp

// Directions:
// Code up a function that returns the character at the input position
// of the function's argument
// The function is demostrated in this document, code up the user input piece
// of this warmUp. Remember the size of your array.
// What are the boundary conditions of this data type?
// Create a new project named warmUpToday'sDate and name your cpp file in the
// project Note: Today is not Aug 12, so you cannot copy and paste this code!
// make your cpp file name the same as your project name: see screen shot in announcement
// and have your instructor check your code before you complete this warmup



// References
// https://www.w3schools.com/cpp/cpp_arrays.asp
// https://www.w3schools.com/cpp/cpp_arrays_multi.asp
// https://www.w3schools.com/cpp/cpp_functions.asp


const int MY_ID = 1234;

// Function Prototype
char findTheChar(int);
char helloWorld[9] = {'S', 'o', 'm', 'e', ' ', 'T', 'e', 'x', 't'};

int main()
{
    int myNum1;
    int maxRange = sizeof(helloWorld);
    cout << "My ID is: " << MY_ID << endl;

    while (myNum1 > maxRange || myNum1 <0)
    {
        cout << "Enter a number to find the character at that position in the array (0-" << maxRange << "): ";
        cin >> myNum1;
        if (myNum1 > maxRange || myNum1 < 0)
        {
            cout << "\nNumber out of range. Try again. ";
        }
    }

    cout << "\nThe character at position " << myNum1 << " is \"" << findTheChar(myNum1) << "\"" << endl;

    return 0;
}

// Function Definition
char findTheChar(int positionInArray)
{
    return helloWorld[positionInArray]; // This could just be in a variable in the main code.
}
