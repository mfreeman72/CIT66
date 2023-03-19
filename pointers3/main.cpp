#include <iostream>

using namespace std;

// Pointers Class video code-along - section 3

int main()
{
    int luckyNumbers[5] = { 2,3,5,7,9 };
    // An array without an index will give the address of the first element of the array
    cout << luckyNumbers << endl;
    // Proof of that
    cout << &luckyNumbers[0] << endl;
    // An array name acts as the pointer, and the [index] acts to dereference that pointer's address location + index number
    cout << luckyNumbers[2] << endl;
    // Proof of that
    cout << *(luckyNumbers+2) << endl;


    int luckyNumbers2[5];

    for (int i=0; i<5; i++)
    {
        cout << "Number: ";
        cin >> luckyNumbers2[i];
    }

    for (int i=0; i<5; i++)
        cout << "Number " << i+1 << ": " << *(luckyNumbers2+i) << endl;

    return 0;
}
