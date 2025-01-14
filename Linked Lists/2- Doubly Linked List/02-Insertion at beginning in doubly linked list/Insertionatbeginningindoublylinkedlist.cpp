#include <iostream>
using namespace std;

// Define a Node for the Doubly Linked List
class Node {
public:
    int data;    // Data part of the Node
    Node* prev;  // Pointer to the previous Node
    Node* next;  // Pointer to the next Node

    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

// Function to insert a node at the beginning of the Doubly Linked List
void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node(value); // Create a new node with the given value
    if (head != nullptr) {
        newNode->next = head; // Point the new node's next to the current head
        head->prev = newNode; // Update the previous pointer of the current head
    }
    head = newNode; // Update the head pointer to the new node
}

// Function to display the Doubly Linked List
void displayList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Main function to test the insertion
int main() {
    Node* head = nullptr; // Initialize an empty Doubly Linked List

    insertAtBeginning(head, 10); // Insert 10 at the beginning
    insertAtBeginning(head, 20); // Insert 20 at the beginning
    insertAtBeginning(head, 30); // Insert 30 at the beginning

    cout << "Doubly Linked List after insertions: ";
    displayList(head);

    return 0;
}
