#include <iostream>
using namespace std;

// Define a Node for the Linked List
class Node {
public:
    int data;    // Data part of the Node
    Node* next;  // Pointer to the next Node
};

// Function to insert a new Node at the beginning of the Linked List
void insertStart(Node** head, int data) {
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

// Function to insert a Node in the middle of the Linked List
void insertMiddle(Node** head, int data) {
    if (*head == nullptr) {
        // If the list is empty, insert at the beginning
        insertStart(head, data);
        return;
    }

    Node* new_node = new Node();
    new_node->data = data;

    // Find the length of the linked list
    Node* temp = *head;
    int length = 0;
    while (temp != nullptr) {
        length++;
        temp = temp->next;
    }

    // Find the middle position
    int mid = length / 2;

    // Traverse to the middle position
    temp = *head;
    for (int i = 1; i < mid; i++) {
        temp = temp->next;
    }

    // Insert the new node at the middle position
    new_node->next = temp->next;
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

int main() {
    Node* head = nullptr; // Initialize an empty Linked List

    int choice, value;

    // Menu-driven program
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert in middle\n";
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
            cout << "Enter value to insert in the middle: ";
            cin >> value;
            insertMiddle(&head, value);
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
