#include <iostream>

using namespace std;

// Pointers Class video code-along - section 5

int main()
{
    int size;
    cout << "Size: ";
    cin >> size;
    //    int myArray[size]; --> causes error because size is not a constant
    int* myArray = new int[size]; // This dynamically allocates array memory, but MUST be deallocated when not needed in order to prevent memory leaks

    for (int i=0; i<size; i++)
    {
        cout << "Array[" << i << "] ";
        cin >> myArray[i];
    }
    for (int i=0; i<size; i++)
    {
        cout << myArray[i] << "  ";
        // Can also use: cout << *(myArray+i) << "  ";
    }

    delete[]myArray;//\
                    //  > -- These two lines deallocate the memory and clear the array pointer
    myArray = NULL; ///

    return 0;
}
