#include <iostream>
using namespace std;

// Define a Node for the Linked List
class Node {
public:
    int data;    // Data part of the Node
    Node* next;  // Pointer to the next Node

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Function to insert a node at the beginning of the Linked List
void insertStart(Node** head, int value) {
    Node* new_node = new Node(value);
    new_node->next = *head; // Point the new node to the current head
    *head = new_node;       // Update the head pointer to the new node
}

// Function to insert a node at a given position
void insertAtPosition(Node** head, int position, int value) {
    Node* new_node = new Node(value);

    // If inserting at the head (position 1)
    if (position == 1) {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    Node* current = *head;
    int currentPosition = 1;

    // Traverse to the node just before the desired position
    while (current != nullptr && currentPosition < position - 1) {
        current = current->next;
        currentPosition++;
    }

    // If the position is out of bounds
    if (current == nullptr) {
        cout << "Position out of bounds.\n";
        delete new_node;
        return;
    }

    // Insert the new node at the specified position
    new_node->next = current->next;
    current->next = new_node;
}

// Function to display the Linked List
void display(Node* node) {
    if (node == nullptr) {
        cout << "The list is empty.\n";
        return;
    }
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr; // Initialize an empty Linked List

    int choice, value, position;

    // Menu-driven program
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at the beginning\n";
        cout << "2. Insert at a given position\n";
        cout << "3. Display list\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert at the beginning: ";
            cin >> value;
            insertStart(&head, value);
            break;

        case 2:
            cout << "Enter the position to insert at: ";
            cin >> position;
            cout << "Enter value to insert: ";
            cin >> value;
            insertAtPosition(&head, position, value);
            break;

        case 3:
            cout << "The Linked List is: ";
            display(head);
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
