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

// Function to insert a new Node at the end of the Linked List
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

// Function to print the Linked List in reverse order using recursion
void printReverse(Node* node) {
    if (node == nullptr) {
        return; // Base case: end of the list
    }
    printReverse(node->next); // Recursive call
    cout << node->data << " "; // Print the current node after recursive call
}

int main() {
    Node* head = nullptr; // Initialize an empty Linked List

    int choice, value;

    // Menu-driven program
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at end\n";
        cout << "2. Display list\n";
        cout << "3. Print reverse without reversing\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert at the end: ";
            cin >> value;
            insertEnd(&head, value);
            break;

        case 2:
            cout << "The Linked List is: ";
            display(head);
            break;

        case 3:
            cout << "The Linked List in reverse order is: ";
            printReverse(head);
            cout << endl;
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
