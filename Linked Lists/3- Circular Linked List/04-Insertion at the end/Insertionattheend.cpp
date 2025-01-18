#include <iostream>
using namespace std;

// Define a Node for the Circular Linked List
class Node {
public:
    int data;    // Data part of the Node
    Node* next;  // Pointer to the next Node

    // Constructor to initialize a new node
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Function to insert a node at the end of the Circular Linked List
void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node(value);

    // If the list is empty
    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
        return;
    }

    // Traverse to the last node
    Node* tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }

    tail->next = newNode;
    newNode->next = head;
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

// Main function to test insertion at the end
int main() {
    Node* head = nullptr; // Initialize an empty Circular Linked List

    int n, value;
    cout << "How many values do you want to insert at the end? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value " << (i + 1) << ": ";
        cin >> value;
        insertAtEnd(head, value);
    }

    cout << "Circular Linked List after insertions: ";
    displayCircularList(head);

    return 0;
}
