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

// Function to insert a new node at the end of the Linked List
void insertEnd(Node** head, int data) {
    Node* new_node = new Node(data);
    if (*head == nullptr) {
        *head = new_node;
        return;
    }
    Node* temp = *head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Function to delete alternate nodes of the Linked List
void deleteAlternateNodes(Node** head) {
    if (*head == nullptr) return;

    Node* current = *head;
    Node* temp;

    while (current != nullptr && current->next != nullptr) {
        temp = current->next;          // Pointer to the node to be deleted
        current->next = temp->next;    // Skip the node to be deleted
        delete temp;                   // Free memory
        current = current->next;       // Move to the next valid node
    }
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
        cout << "1. Insert at end\n";
        cout << "2. Delete alternate nodes\n";
        cout << "3. Display list\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            insertEnd(&head, value);
            break;

        case 2:
            deleteAlternateNodes(&head);
            cout << "Alternate nodes deleted.\n";
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
