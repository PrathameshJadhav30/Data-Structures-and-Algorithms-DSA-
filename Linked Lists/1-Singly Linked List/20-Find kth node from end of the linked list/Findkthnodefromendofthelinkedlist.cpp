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

// Function to find the kth node from the end of the Linked List
void findKthFromEnd(Node* head, int k) {
    if (head == nullptr) {
        cout << "The list is empty.\n";
        return;
    }

    Node* first = head;
    Node* second = head;

    // Move the first pointer k nodes ahead
    for (int i = 0; i < k; i++) {
        if (first == nullptr) {
            cout << "The list has fewer than " << k << " nodes.\n";
            return;
        }
        first = first->next;
    }

    // Move both pointers until the first pointer reaches the end
    while (first != nullptr) {
        first = first->next;
        second = second->next;
    }

    cout << "The " << k << "th node from the end is: " << second->data << endl;
}

int main() {
    Node* head = nullptr; // Initialize an empty Linked List

    int choice, value, k;

    // Menu-driven program
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Display list\n";
        cout << "3. Find kth node from end\n";
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
            cout << "Enter the value of k: ";
            cin >> k;
            findKthFromEnd(head, k);
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
