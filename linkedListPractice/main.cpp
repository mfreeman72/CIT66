#include <iostream>

using namespace std;

class Node
{
public:
    int num;
    Node* next;
};

void printList(Node* n)
{
    while(n != NULL)
    {
        cout << n->num << endl;
        n = n->next;
    }
}

int main()
{
    Node* head = new Node();
    head->num = 0;
    Node* current = head;

    for (int i=1; i<10000; i++)
    {
        Node* newNode = new Node();
        newNode->num = i;
        current->next = newNode;
        current = newNode;
    }
    printList(head);
    return 0;
}
