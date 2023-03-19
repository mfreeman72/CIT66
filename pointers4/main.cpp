#include <iostream>

using namespace std;

// Pointers Class video code-along - section 4

// Function to get minimum and maximum numbers in an array
void getMinAndMax(int numbers[], int size, int* min, int* max) // the * means that instead of accepting an integer variable, it accepts the pointer to the variable's memory location
{
    // Iterate through all the numbers except the first, since the first is already stored in the min and max variables
    for (int i = 1; i < size; i++)
    {
        // Compare each item in the array with the current dereferenced max value
        // If the item in the array index is greater than the dereferenced max value, then make the dereferenced max value equal to the array item
        if (numbers[i] > *max)
            *max = numbers[i];
        // Compare each item in the array with the current dereferenced min value
        // If the item in the array index is less than the dereferenced min value, then make the dereferenced min value equal to the array item
        if (numbers[i] < *min)
            *min = numbers[i];
        // Since we are changing the min and max variables by their pointer reference, then no return value is needed
    }
}


int main()
{
    // Setup an array of 5 numbers
    int numbers[5] = {5,4,-2,29,6};
    // Instead of using a return value, we can set variables, then pass their memory location to the function to change them directly
    int min = numbers[0]; // Set min to the first number in the array
    int max = numbers[0]; // Set max to the first pointer in the array
    getMinAndMax(numbers, 5, &min, &max); // send the array's pointer, the number of items in the array, and the memory locations for the min and max variables to the function
    // Since the variables were changed by pointer reference, we can just print the variables directly.
    cout << "Min is " << min << endl;
    cout << "Max is " << max << endl;
    return 0;
}
