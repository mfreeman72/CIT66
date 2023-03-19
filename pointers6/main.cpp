#include <iostream>

using namespace std;

// Pointers Class video code-along - section 6

// 2D dynamic arrays

int main()
{
    int rows, cols;
    cout << "Rows, columns: ";
    cin >> rows >> cols;

    // Creating a 2D dynamic array is in multiple steps.
    // 1. Create a pointer to a pointer (called table in this example)
    // 2. Assign that to a new dynamic array representing rows, which will store pointers
    // 3. For each row, assign a new dynamic array representing columns, which will store the final value that you are assigning to that row/column coordinate

    int **table = new int*[rows]; // Creates the pointer "table" that points to a dynamic array of pointers called "rows"
    for (int i=0; i<rows; i++)
    {
        table[i] = new int[cols]; // Creates a dynamic array called columns connected to each pointer in "rows"
    }

    table[1][2] = 88; // Calls the "table" pointer, finds the pointer stored in the "row"  1, then gets the memory location for column 2, and assigns the value of 88 to that location.

    // To deallocate the memory space, it must be redone in reverse order:
    for (int i=0; i<rows; i++)
    {
        delete[] table[i]; // Deletes the dynamic array "cols" at each of the pointer addresses stored in the dynamic array "rows"
    }
    delete[] table; // Deletes the dynamic array "cols" at the pointer stored in "table"
    table = NULL; // Nullifies "table" so that we aren't storing a memory location that no longer belongs to the program


    return 0;
}
