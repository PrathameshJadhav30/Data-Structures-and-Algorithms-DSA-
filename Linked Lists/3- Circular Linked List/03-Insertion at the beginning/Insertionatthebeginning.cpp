#include <iostream>
using namespace std;

// Define a Node for the Circular Linked List
class Node {
public:
    int data;    // Data part of the Node
    Node* next;  // Pointer to the next Node

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Function to insert a node at the beginning of the Circular Linked List
void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node(value);

    // If the list is empty
    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }

    newNode->next = head;
    tail->next = newNode;
    head = newNode;
}

// Function to display the Circular Linked List
void displayCircularList(Node* head) {
    if (head == nullptr) {
        cout << "The list is empty.\n";
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

// Main function to test insertion at the beginning
int main() {
    Node* head = nullptr; // Initialize an empty Circular Linked List

    int value;
    cout << "Enter value to insert at the beginning: ";
    cin >> value;

    insertAtBeginning(head, value);

    cout << "Circular Linked List after insertion: ";
    displayCircularList(head);

    return 0;
}
