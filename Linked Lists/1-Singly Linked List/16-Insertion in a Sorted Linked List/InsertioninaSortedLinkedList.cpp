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

// Function to insert a new node in a sorted singly linked list
void insertSorted(Node** head, int data) {
    Node* new_node = new Node(data);

    // If the list is empty or the new node should be the new head
    if (*head == nullptr || (*head)->data >= data) {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    // Traverse the list to find the correct position
    Node* current = *head;
    while (current->next != nullptr && current->next->data < data) {
        current = current->next;
    }

    // Insert the new node in its correct position
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

    int choice, value;

    // Menu-driven program
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert into sorted list\n";
        cout << "2. Display list\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            insertSorted(&head, value);
            break;

        case 2:
            cout << "The Linked List is: ";
            display(head);
            break;

        case 3:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
