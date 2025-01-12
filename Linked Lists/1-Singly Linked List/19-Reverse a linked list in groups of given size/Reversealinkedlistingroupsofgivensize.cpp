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

// Function to reverse a linked list in groups of given size
Node* reverseInGroups(Node* head, int k) {
    if (head == nullptr) return nullptr;

    Node* current = head;
    Node* prev = nullptr;
    Node* next = nullptr;
    int count = 0;

    // Reverse first k nodes of the list
    while (current != nullptr && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    // Next is now pointing to the (k+1)th node
    // Recursively call for the remaining list and link the two sublists
    if (next != nullptr) {
        head->next = reverseInGroups(next, k);
    }

    // Prev becomes the new head of the reversed group
    return prev;
}

int main() {
    Node* head = nullptr; // Initialize an empty Linked List

    int choice, value, groupSize;

    // Menu-driven program
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Display list\n";
        cout << "3. Reverse in groups of size K\n";
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
            cout << "Enter the group size (K): ";
            cin >> groupSize;
            head = reverseInGroups(head, groupSize);
            cout << "The list after reversing in groups of size " << groupSize << " is: ";
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
