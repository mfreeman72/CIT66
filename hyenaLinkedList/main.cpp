#include <iostream>

using namespace std;

// Create Node class
class Node
{
public:
    string name;
    Node* next;
};

// Function to traverse through the linked list and print contents
void printList(Node* traverser)
{
    // Check to make sure traverser pointer is not at the end of the list
    while(traverser!=NULL)
    {
        // Print the name in current node
        cout << traverser->name << endl;
        // Advance the traverser pointer
        traverser = traverser->next;
    }
}

// Function to add a new node to the list and insert new name
void insertNew(Node** head, string newName)
{
    // Create a new node
    Node* newNode = new Node();
    // Fill in the new name content
    newNode->name = newName;
    // Set the next pointer to NULL, since it's at the end
    newNode->next = NULL;
    // Set the traversing pointer to the head
    Node* last = *head;
    // Traverse to find the end
    while(last->next!=NULL)
        // If not the end, set the last pointer to the next pointer
        last = last->next;
    // Once the end is found, set next to the new node to link it to the list
    last->next = newNode;
}

int main()
{
    // Initialize the hyenaName variable for entering the name
    string hyenaName;

    // Create the initial head node
    Node* head = new Node();
    //  Set the tail to the head for first and (currently) only node
    Node* tail = head;

    // Check for "exit" response. If so, end
    while(hyenaName != "exit")
    {
        // Enter a new name
        cout << "Enter a new hyena name, or type exit to quit: ";
        cin >> hyenaName;
        // Check for exit response to not add it to the list
        if(hyenaName != "exit")
        {
            // Insert the entered name after the tail
            insertNew(&tail, hyenaName);
            // Print the current list of names starting with the head node
            cout << endl;
            printList(head);
            cout << endl;
        }
    }
    return 0;
}
