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

// Function to append the last n nodes to the beginning of the Linked List
void appendLastNToStart(Node** head, int n) {
    if (*head == nullptr || n <= 0) {
        cout << "Invalid input or list is empty.\n";
        return;
    }

    // Count the total number of nodes in the list
    int totalNodes = 0;
    Node* temp = *head;
    while (temp != nullptr) {
        totalNodes++;
        temp = temp->next;
    }

    // Check if n is greater than or equal to the total number of nodes
    if (n >= totalNodes) {
        cout << "n is greater than or equal to the total number of nodes. No change made.\n";
        return;
    }

    // Find the (totalNodes - n)th node
    int splitPoint = totalNodes - n;
    Node* current = *head;
    Node* prev = nullptr;

    for (int i = 0; i < splitPoint; i++) {
        prev = current;
        current = current->next;
    }

    // Update the pointers to rearrange the list
    prev->next = nullptr; // Break the list at the split point
    Node* newHead = current;

    // Traverse to the end of the new list
    while (current->next != nullptr) {
        current = current->next;
    }

    // Link the end of the new list to the old head
    current->next = *head;

    // Update the head pointer
    *head = newHead;
}

int main() {
    Node* head = nullptr; // Initialize an empty Linked List

    int choice, value, n;

    // Menu-driven program
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Display list\n";
        cout << "3. Append last n nodes to start\n";
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
            cout << "The Linked List is: ";
            display(head);
            break;

        case 3:
            cout << "Enter the value of n: ";
            cin >> n;
            appendLastNToStart(&head, n);
            cout << "The list after appending last " << n << " nodes to start is: ";
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
