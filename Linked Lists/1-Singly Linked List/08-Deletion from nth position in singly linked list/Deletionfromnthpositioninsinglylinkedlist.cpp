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

// Function to delete the nth Node from the Linked List
void deleteNthNode(Node** head, int position) {
    if (*head == nullptr) {
        cout << "The list is empty. Nothing to delete.\n";
        return;
    }

    // Handle deletion of the head node (position 0)
    if (position == 0) {
        Node* temp = *head;
        *head = (*head)->next;
        delete temp;
        cout << "Node at position " << position << " deleted.\n";
        return;
    }

    Node* current = *head;
    Node* previous = nullptr;

    // Traverse the list to find the node at the given position
    for (int i = 0; i < position; i++) {
        previous = current;
        if (current->next == nullptr) {  // If position is out of bounds
            cout << "Position " << position << " is out of bounds.\n";
            return;
        }
        current = current->next;
    }

    // Unlink the node and delete it
    previous->next = current->next;
    delete current;

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
        cout << "1. Insert at beginning\n";
        cout << "2. Delete nth node\n";
        cout << "3. Display list\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            insertStart(&head, value);
            break;

        case 2:
            cout << "Enter position of node to delete (0-based index): ";
            cin >> position;
            deleteNthNode(&head, position);
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
