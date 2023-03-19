#include <iostream>

using namespace std;

// Set up integer and character arrays
int sortIntList[10] = {6,3,1,2,5,4,9,0,7,8};
char sortCharList[10] = {'f','c','a','b','e','d','i','j','g','h'};

// Set up linked list node classes for integer and characters
class IntNode
{
public:
    int number;
    IntNode* next;
};

class CharNode
{
public:
    char letter;
    CharNode* next;
};

// Function to swap two variable's values
template<typename T> // Creates a generic data type called T

void swapem(T& a, T& b) // Creates a function that can use any datatype using generic template
{
    T temp = a;
    a = b;
    b = temp;
}

// Function to print integer linked list
void printIntList(IntNode* n)
{
    while(n != NULL)
    {
        cout << n->number << "  ";
        n = n->next;
    }
    cout << endl;
}

// Function to print character linked list
void printCharList(CharNode* n)
{
    while(n != NULL)
    {
        cout << n->letter << "  ";
        n = n->next;
    }
    cout << endl;
}

// Function to bubble sort integer linked list
void sortIntegers(IntNode* n)
{
    for(int i=0; i<9; i++)
    {
        IntNode* current = n;
        IntNode* compare = n->next;
        while(current->next != NULL)
        {
            if(current->number > compare->number)
                swapem(current->number,compare->number);
            current = compare;
            compare = current->next;
        }
    }
}

// Function to bubble sort character linked list
void sortCharacters(CharNode* n)
{
    for(int i=0; i<9; i++)
    {
        CharNode* current = n;
        CharNode* compare = n->next;
        while(current->next != NULL)
        {
            if(current->letter > compare->letter)
                swapem(current->letter,compare->letter);
            current = compare;
            compare = current->next;
        }
    }
}

int main()
{
    // Create linked lists from array data

    // Setup integer head and tail nodes
    IntNode* intHead = new IntNode();
    intHead->number = sortIntList[0];
    IntNode* intTail = intHead;

    // Setup character head and tail nodes
    CharNode* charHead = new CharNode();
    charHead->letter = sortCharList[0];
    CharNode* charTail = charHead;

    // Iterate through arrays, adding values to linked lists
    for(int i=1; i<10; i++)
    {
        // Set each integer node to integer array index [i]
        IntNode* newIntNode = new IntNode();
        newIntNode->number = sortIntList[i];
        intTail->next = newIntNode;
        intTail = newIntNode;

        // Set each character node to character array index [i]
        CharNode* newCharNode = new CharNode();
        newCharNode->letter = sortCharList[i];
        charTail->next = newCharNode;
        charTail = newCharNode;
    }

    // Sort and print linked lists
    cout << "\n\nPrinting Sorted Linked Lists..." << endl;

    sortIntegers(intHead);
    printIntList(intHead);
    sortCharacters(charHead);
    printCharList(charHead);

    // Sort and print arrays
    cout << "\n\nPrinting sorted arrays..." << endl;

    // Bubble sort integer array
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9-i; j++)
        {
            if(sortIntList[j] > sortIntList[j+1])
                swapem(sortIntList[j],sortIntList[j+1]);
        }
    }

    // Print integer array
    for(int i=0; i<10; i++)
    {
        cout << sortIntList[i] << "  ";
    }
    cout << endl;

    // Bubble sort character array
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9-i; j++)
        {
            if(sortCharList[j] > sortCharList[j+1])
                swapem(sortCharList[j],sortCharList[j+1]);
        }
    }

    // Print character array
    for(int i=0; i<10; i++)
    {
        cout << sortCharList[i] << "  ";
    }

    return 0;
}
