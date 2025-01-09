#include <iostream>
using namespace std;

// Node class representing each element in the linked list
class Node {
public:
    int data;  // Data stored in the node
    Node *next;  // Pointer to the next node
};

// Global variable to track the size of the linked list
int listSize = 0;

// Function to insert a node at the beginning of the linked list
void insertAtHead(Node **head, int data) {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    listSize++;  // Increment the size of the linked list
}

// Function to insert a node at a specific position in the linked list
void insertAtPosition(Node **head, int pos, int data) {
    // Create a new node
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    // Validate the position
    if (pos < 1 || pos > listSize + 1) {
        cout << "Invalid position. Please enter a position between 1 and " << listSize + 1 << "." << endl;
        delete newNode;  // Free memory for the unused node
        return;
    }

    // Insert at the head if position is 1
    if (pos == 1) {
        newNode->next = *head;
        *head = newNode;
    } else {
        // Traverse to the node just before the desired position
        Node *temp = *head;
        for (int i = 1; i < pos - 1; ++i) {
            temp = temp->next;
        }
        // Insert the new node at the desired position
        newNode->next = temp->next;
        temp->next = newNode;
    }
    listSize++;  // Increment the size of the linked list
}

// Function to display the linked list
void display(Node *node) {
    cout << "Linked List: ";
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node *head = nullptr;  // Initialize an empty linked list

    // Insert some initial nodes at the head
    insertAtHead(&head, 140);
    insertAtHead(&head, 120);
    insertAtHead(&head, 80);
    insertAtHead(&head, 60);
    insertAtHead(&head, 20);

    // Display the initial linked list
    display(head);

    // Allow the user to input data and position for new insertions
    int choice;
    do {
        cout << "\n1. Insert at a specific position\n2. Display linked list\n3. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int data, pos;
            cout << "Enter the data to insert: ";
            cin >> data;
            cout << "Enter the position to insert (1 to " << listSize + 1 << "): ";
            cin >> pos;
            insertAtPosition(&head, pos, data);
            break;
        }
        case 2:
            display(head);
            break;
        case 3:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
