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

// Function to delete the last Node from the Linked List
void deleteFromEnd(Node** head) {
    if (*head == nullptr) {
        cout << "The list is empty. Nothing to delete.\n";
        return;
    }

    // If there is only one node
    if ((*head)->next == nullptr) {
        delete *head;
        *head = nullptr;
        cout << "Last node deleted. The list is now empty.\n";
        return;
    }

    // Traverse to the second-last node
    Node* current = *head;
    while (current->next->next != nullptr) {
        current = current->next;
    }

    // Delete the last node
    delete current->next;
    current->next = nullptr;
    cout << "Last node deleted.\n";
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
        cout << "2. Delete from end\n";
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
            deleteFromEnd(&head);
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
