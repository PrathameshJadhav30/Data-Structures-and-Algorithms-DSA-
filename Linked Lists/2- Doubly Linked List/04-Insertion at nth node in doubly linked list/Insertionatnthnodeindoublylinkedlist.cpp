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

// Function to insert a node at the nth position in the Doubly Linked List
void insertAtNth(Node*& head, int position, int value) {
    Node* newNode = new Node(value); // Create a new node with the given value

    // If inserting at the head (position 1)
    if (position == 1) {
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
        return;
    }

    Node* temp = head;
    int currentPosition = 1;

    // Traverse to the node just before the desired position
    while (temp != nullptr && currentPosition < position - 1) {
        temp = temp->next;
        currentPosition++;
    }

    // If the position is out of bounds
    if (temp == nullptr) {
        cout << "Position out of bounds.\n";
        delete newNode;
        return;
    }

    // Insert the new node at the specified position
    newNode->next = temp->next;
    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }
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

    insertAtNth(head, 1, 10); // Insert 10 at position 1
    insertAtNth(head, 2, 20); // Insert 20 at position 2
    insertAtNth(head, 3, 30); // Insert 30 at position 3

    cout << "Doubly Linked List after insertions at nth positions: ";
    displayList(head);

    insertAtNth(head, 2, 15); // Insert 15 at position 2
    cout << "Doubly Linked List after insertion at position 2: ";
    displayList(head);

   
    return 0;
}