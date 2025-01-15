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

// Function to insert a node at the end of the Doubly Linked List
void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node(value); // Create a new node with the given value

    // If the list is empty
    if (head == nullptr) {
        head = newNode;
        return;
    }

    // Traverse to the last node
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // Update the last node's next pointer and new node's prev pointer
    temp->next = newNode;
    newNode->prev = temp;
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

    insertAtEnd(head, 10); // Insert 10 at the end
    insertAtEnd(head, 20); // Insert 20 at the end
    insertAtEnd(head, 30); // Insert 30 at the end

    cout << "Doubly Linked List after insertions: ";
    displayList(head);

    return 0;
}
