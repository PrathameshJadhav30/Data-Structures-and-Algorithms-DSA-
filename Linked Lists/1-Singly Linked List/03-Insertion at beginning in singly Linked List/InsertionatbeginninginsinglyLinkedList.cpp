#include <iostream>
using namespace std;

// Definition of a Node in the Linked List
class Node {
public:
    int data;    // Data stored in the Node
    Node* next;  // Pointer to the next Node in the Linked List
};

// Function to insert a new Node at the front of the Linked List
void insertFront(Node** head, int data) {
    // Create a new Node
    Node* new_node = new Node();

    // Assign the data to the new Node
    new_node->data = data;

    // Point the next of the new Node to the current head
    new_node->next = *head;

    // Update the head to point to the new Node
    *head = new_node;

    // Print the inserted item
    cout << "Inserted Item: " << new_node->data << endl;
}

// Function to print the Linked List
void printList(Node* node) {
    cout << "\nLinked List: ";

    // Traverse the Linked List until the end
    while (node != NULL) {
        cout << node->data << " "; // Print the data of the current Node
        node = node->next;         // Move to the next Node
    }
    cout << endl;
}

int main() {
    // Initialize the head of the Linked List as NULL
    Node* head = NULL;

    // Insert elements at the front of the Linked List
    insertFront(&head, 4);
    insertFront(&head, 5);
    insertFront(&head, 6);
    insertFront(&head, 7);
    insertFront(&head, 8);
    insertFront(&head, 9);

    // Print the Linked List
    printList(head);

    return 0;
}
