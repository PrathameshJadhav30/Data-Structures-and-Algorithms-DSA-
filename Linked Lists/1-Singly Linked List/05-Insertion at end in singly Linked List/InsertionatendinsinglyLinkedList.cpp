#include<iostream>
using namespace std;

// Define the Node class to represent each element in the linked list
class Node {
public:
    int data; // Data stored in the node
    Node* next; // Pointer to the next node in the list
};

// Function to insert a new node at the end of the linked list
void insertEnd(Node** head, int data) {
    // Create a new node
    Node* freshNode = new Node();
    freshNode->data = data; // Assign data to the new node
    freshNode->next = NULL; // The new node will point to NULL (end of list)

    // If the linked list is empty, make the new node the head
    if (*head == NULL) {
        *head = freshNode;
        cout << freshNode->data << " inserted" << endl;
        return;
    }

    // Traverse to the last node in the linked list
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Link the last node to the new node
    temp->next = freshNode;
    cout << freshNode->data << " inserted" << endl;
}

// Function to display all the elements in the linked list
void display(Node* node) {
    // Traverse the linked list and print each node's data
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl; // Print a newline after displaying all nodes
}

int main() {
    Node* head = NULL; // Initialize the head of the linked list
    int choice, value;

    // Menu-driven program to manage the linked list
    do {
        cout << "\n1. Insert at End" << endl;
        cout << "2. Display Linked List" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                insertEnd(&head, value);
                break;
            case 2:
                cout << "Linked List: ";
                display(head);
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
