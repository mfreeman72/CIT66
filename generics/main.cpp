#include <iostream>

using namespace std;

template<typename T> // Creates a generic data type called T

void swapem(T& a, T& b) // Creates a function that can use any datatype using generic template
{
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a=5, b=7;
    cout << a << " - " << b << endl;
    swapem(a,b);
    cout << a << " - " << b << endl;

    char c='c', d='d';
    cout << c << " - " << d << endl;
    swapem(c,d);
    cout << c << " - " << d << endl;
    return 0;
}
