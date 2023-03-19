#include <iostream>

using namespace std;

// Pointers Class video code-along - section 1

int main()
{
    // A variable stores a value at an address location
    int n = 5;
    // & --> means "address of", so &n means "address of the n variable"
    cout << &n << endl;
    // * means pointer data type; called a "dereference"
    int* ptr = &n;
    // ptr without * will give the address
    cout << ptr << endl;
    // ptr with * will give the value
    cout << *ptr << endl;
    // pointer value can be reassigned
    *ptr = 10;
    cout << *ptr << endl;
    // reassigned value also shows up in the variable connected to that address
    cout << n << endl;

    // A pointer must first be initialized with a variable, otherwise the memory location for the pointer can't exist
    int v;
    int* ptr2 = &v;
    *ptr2 = 7;
    cout << "v = " << v << endl;

    int x = 100;
    int* myPointer = &x;
    cout << "This should be a value: " << *myPointer << endl;
    cout << "This should be an address: " << myPointer << endl;

    return 0;
}
