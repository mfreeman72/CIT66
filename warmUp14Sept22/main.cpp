#include <iostream>

using namespace std;

// mF warmUp14sept22

// Function prototypes
void myArrayFunction();
void myArrayFunction02(int,int);

// main() function
int main()
{
    // Intro
    cout << "Welcome to WarmUp Sept 14, 2022!" << endl;

    // myArray Function calls
    myArrayFunction();
    myArrayFunction02(2,2);

    return 0;
}

void myArrayFunction()
{
    cout << "\nHello from myArray Function!" << endl;

    // Create an array containing strings of zoo animal names
    string zooAnimals[4] = {"lion","tiger","bear","snake"};

    // Print out each array value in order
    cout << "zooAnimals[0] = " << zooAnimals[0] << endl;
    cout << "zooAnimals[1] = " << zooAnimals[1] << endl;
    cout << "zooAnimals[2] = " << zooAnimals[2] << endl;
    cout << "zooAnimals[3] = " << zooAnimals[3] << endl << endl;

    // Use a for() loop to print out each array value in order
    for(int i=0; i<4; i++)
    {
        cout << "zooAnimals[" << i << "] = " << zooAnimals[i] << endl;
    }
}

void myArrayFunction02(int numRows, int numCols)
{
    cout << "\nHello from myArray Function02!" << endl;

    // Use the arguments passed to myArrayFunction02 to create the 2D array!
    int myNumberTable[numRows][numCols] =
    {
        {1, 2},
        {3, 4}
    };

    // Output the myNumberTable 2D array
    cout << "myNumberTable[0][0] = " << myNumberTable[0][0] << endl;
    cout << "myNumberTable[0][1] = " << myNumberTable[0][1] << endl;
    cout << "myNumberTable[1][0] = " << myNumberTable[1][0] << endl;
    cout << "myNumberTable[1][1] = " << myNumberTable[1][1] << endl << endl;

    // Output the myNumberTable 2D array using a for() loop
    for(int i=0; i<numRows; i++)
    {
        for(int j=0; j<numCols; j++)
        {
            cout << "myNumberTable[" << i << "][" << j << "] = " << myNumberTable[i][j] << endl;
        }
    }

}
