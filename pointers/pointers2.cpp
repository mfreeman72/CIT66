#include <iostream>

using namespace std;

// Pointers Class video code-along

void printNumber(int* numberPtr)
{
    cout << *numberPtr << endl;
}

int main()
{
    int number = 5;
    printNumber(&number);

    return 0;
}
