// mF 11/14/2022
// Binary search example
//
// This program will set up an array of 1024 integers beginning at a random number between 0 and 9,
// with numbers increasing at intervals ranging from 1 to 3, so there may be gaps between numbers in the list.
// The user will enter a number to search for. The program will attempt to find the number in both sequential
// and binary searches, and if found, will tell the user where in the array it is. Otherwise, it will tell the
// user that the number was not found.

#include <iostream>

using namespace std;

int main()
{
    // Define array
    int sortedArray[1024];

    // Define/initialize variables
    bool found = false;
    int num;
    int searches = 0;
    int upperLimit = 1023;
    int lowerLimit = 0;
    int current = 1023/2;

    // Set up random number generator
    srand((unsigned) time(NULL));

    // Assign the first random number into the first position in the array
    int random = rand() %10;
    sortedArray[0] = random;

    // Fill in the rest of the array, randomly skipping some numbers
    for (int i = 1; i<1024; i++)
    {
        random = rand() %3;
        sortedArray[i] = sortedArray[i-1] + random + 1;
    }

    // Tell user the array was setup
    cout << "An array is setup with a sorted list of random numbers.\nThere are gaps between the numbers, so some numbers are missing." << endl;

    // Get a number from the user
    cout << "\nPlease enter a number to find between " << sortedArray[0] << " and " << sortedArray[1023] << ": ";
    cin >> num;

    // Perform sequential search for the user's number

    // Iterate through entire list
    for (int i = 0; i<1024; i++)
    {
        // If user's number is found at array position i, let the user know, and set the found boolean to true
        if (sortedArray[i] == num)
        {
            cout << "\nSequential: Found your number (" << num << ") at array position [" << i << "] in " << i+1 << " iterations." << endl;
            found = true;
        }
    }
    // If the users number was not found, let the user know
    if (found == false)
        cout << "\nSequential: Your number is not found in the array after 1024 iterations." << endl;

    // Perform binary search for the user's number

    // Loop while the current array position isn't the user's number,
    // and as long as we haven't reached the endpoint where the limits pass each other
    while ((sortedArray[current] != num) && (lowerLimit < upperLimit))
    {
        // If the user's number is less than the current array position's number, set the upper limit to one less than the current position
        if (num<sortedArray[current])
            upperLimit = current-1;
        // Otherwise, set the lower limit to one more than the current position
        else
            lowerLimit = current+1;
        // Set the new current array position to half-way between the new upper/lower limits
        current = ((upperLimit - lowerLimit) / 2) + lowerLimit;
        // Increase the number of searches done to track the number of iterations before finding the user's number
        searches++;
    }

    // Let the user know where their number was found, or if it wasn't found.
    if (num == sortedArray[current])
        cout << "\nBinary: Found your number (" << num << ") at array position [" << current << "] in " << searches << " iterations." << endl;
    else
        cout << "\nBinary: Your number is not found in the array after " << searches << " iterations." << endl;

    return 0;
}
