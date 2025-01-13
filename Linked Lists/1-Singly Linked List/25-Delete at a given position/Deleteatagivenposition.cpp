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

// Function to delete a node at a given position
void deleteAtPosition(Node** head, int position) {
    if (*head == nullptr) {
        cout << "The list is empty. Nothing to delete.\n";
        return;
    }

    Node* temp = *head;

    // If the head needs to be removed (position 1)
    if (position == 1) {
        *head = temp->next; // Update the head pointer
        delete temp;        // Free the memory of the old head
        cout << "Node at position 1 deleted.\n";
        return;
    }

    // Find the node just before the one to be deleted
    Node* prev = nullptr;
    for (int i = 1; temp != nullptr && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }

    // If the position is out of bounds
    if (temp == nullptr) {
        cout << "Position out of bounds. No node deleted.\n";
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;

    // Free memory of the node to be deleted
    delete temp;

    cout << "Node at position " << position << " deleted.\n";
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
        cout << "2. Delete at a given position\n";
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
            cout << "Enter the position to delete: ";
            cin >> position;
            deleteAtPosition(&head, position);
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
