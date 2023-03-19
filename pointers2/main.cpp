#include <iostream>

using namespace std;

// Pointers Class video code-along - section 2

void printNumber(int* numberPtr)
{
    cout << "This is from printNumber() and expecting an int value: " << *numberPtr << endl;
}

void printLetter(char* charPtr)
{
    cout << "This is from printLetter() and expecting a char: " << *charPtr << endl;
}

void print(void* ptr, char type)
{
    switch (type)
    {
        case 'i': cout << *((int*)ptr) << endl; break;
        case 'c': cout << *((char*)ptr) << endl; break;
    }
}

int main()
{
    int number = 5;
    char letter = 'a';
//    printNumber(&number);
//    printLetter(&letter);
    print(&number,'i');
    print(&letter,'c');
    return 0;
}
