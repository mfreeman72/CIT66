#include <iostream>

using namespace std;

class Node // Create Node structure class
{
public:
    int value;  // Node value
    Node* Next; // pointer to next node
};

void printList(Node* n) // n becomes the traversing pointer, which is initially the location of the first node sent to the printList function
{
    while(n!=NULL) // Cycle a traversing pointer through the linked list until it reaches NULL
    {
        cout << n->value << endl;   // Print the value in the node the traversing pointer is currently pointing to
        n = n->Next;                // Reassign the traversing pointer to the address of the next node
    }
}

void insertAtTheFront(Node** head, int newValue)
{
    // 1. Prepare a new node
    Node* newNode = new Node();
    newNode->value = newValue;
    // 2. Put it in front of current head
    newNode->Next = *head;
    // 3. Move head of the list to point to the new node
    *head = newNode;
}

void insertAtTheEnd(Node** head, int newValue)
{
    // 1. Prepare a new node
    Node* newNode = new Node();
    newNode->value = newValue;
    newNode->Next = NULL;
    // 2. If linked list is empty, newNode will be head node
    if(*head == NULL)
    {
        *head = newNode;
        return;
    }
    // 3. Find the last node
    Node* last = *head;
    while(last->Next!=NULL)
    {
        last = last->Next;
    }
    // 4. Insert newNode after the last node
    last->Next = newNode;
}

void insertAfter(Node* previous, int newValue)
{
    // 1. Check if previous node is NULL
    if(previous == NULL)
    {
        cout << "Previous cannot be NULL";
        return;
    }
    // 2. Prepare a newNode
    Node* newNode = new Node();
    newNode->value = newValue;
    // 3. Insert newNode after previous element
    newNode->Next = previous->Next;
    previous->Next = newNode;
}

int main()
{
    Node* head = new Node();    // Create head node
    Node* second = new Node();  // Create second node
    Node* third = new Node();   // Create third node

    head->value = 1;     // Assign the value of 1 to head node
    head->Next = second; // Point head node to second node

    second->value = 2;   // Assign the value of 2 to second node
    second->Next = third;// Point second node to third node

    third->value = 3;    // Assign the value of 3 to third node
    third->Next = NULL;  // Point third node to NULL

//    insertAtTheFront(&head, -1);
//
//    insertAtTheFront(&head, -2);
//
//    insertAtTheEnd(&head, 4);
//
//    insertAtTheEnd(&head, 5);

    insertAfter(head, -1);
    insertAfter(second, -2);

    printList(head);
    return 0;
}
