// Using Struct
#include <iostream> // Include input/output stream library

using namespace std;

// Structure representing a single node in the linked list
struct Node
{
    int data;    // Data stored in the node
    Node* next;  // Pointer to the next node in the list
};

// Function to insert a new node at the start of the linked list
void insertStart(Node** head, int data)
{
    Node* newNode = new Node; // Allocate memory for the new node
    newNode->data = data;     // Set the data of the new node
    newNode->next = *head;    // Point the new node to the current head

    *head = newNode;          // Update the head to the new node
    cout << "\n" << newNode->data << " inserted at the start" << endl;
}

// Function to delete the first node of the linked list
void deleteStart(Node** head)
{
    // Check if the list is empty
    if (*head == nullptr)
    {
        cout << "Linked List is empty, nothing to delete" << endl;
        return;
    }

    Node* temp = *head;       // Temporarily store the current head
    *head = (*head)->next;    // Move the head pointer to the next node

    cout << "\n" << temp->data << " deleted from the start" << endl;
    delete temp;              // Free the memory of the deleted node
}

// Function to display the linked list elements
void display(Node* node)
{
    cout << "\nLinked List: ";

    // Traverse the list and print each node's data
    while (node != nullptr)
    {
        cout << node->data << " ";
        node = node->next; // Move to the next node
    }
    cout << endl; // Print a newline at the end
}

// Main function to demonstrate linked list operations
int main()
{
    Node* head = nullptr; // Initialize the linked list as empty

    // Insert elements into the linked list
    insertStart(&head, 100);
    insertStart(&head, 80);
    insertStart(&head, 60);
    insertStart(&head, 40);
    insertStart(&head, 20);

    // Display the linked list
    display(head);

    // Delete the first two nodes
    deleteStart(&head);
    deleteStart(&head);

    // Display the updated linked list
    display(head);

    return 0; // Indicate successful program termination
}
