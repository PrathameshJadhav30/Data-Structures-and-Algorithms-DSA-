#include <iostream>
using namespace std;

// Define a Node for the Doubly Linked List
class Node {
public:
    int data;    // Data part of the Node
    Node* prev;  // Pointer to the previous Node
    Node* next;  // Pointer to the next Node

    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

// Function to insert a node at the beginning of the Doubly Linked List
void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (head != nullptr) {
        head->prev = newNode;
    }
    newNode->next = head;
    head = newNode;
}

// Function to insert a node at the end of the Doubly Linked List
void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to insert a node at a specific position in the Doubly Linked List
void insertAtPosition(Node*& head, int position, int value) {
    if (position == 1) {
        insertAtBeginning(head, value);
        return;
    }
    Node* newNode = new Node(value);
    Node* temp = head;
    int currentPosition = 1;

    while (temp != nullptr && currentPosition < position - 1) {
        temp = temp->next;
        currentPosition++;
    }

    if (temp == nullptr) {
        cout << "Position out of bounds.\n";
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

// Function to delete a node at the beginning of the Doubly Linked List
void deleteAtBeginning(Node*& head) {
    if (head == nullptr) {
        cout << "The list is empty.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    delete temp;
}

// Function to delete a node at the end of the Doubly Linked List
void deleteAtEnd(Node*& head) {
    if (head == nullptr) {
        cout << "The list is empty.\n";
        return;
    }
    Node* temp = head;
    if (temp->next == nullptr) {
        head = nullptr;
        delete temp;
        return;
    }
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->prev->next = nullptr;
    delete temp;
}

// Function to delete a node at a specific position in the Doubly Linked List
void deleteAtPosition(Node*& head, int position) {
    if (head == nullptr) {
        cout << "The list is empty.\n";
        return;
    }

    if (position == 1) {
        deleteAtBeginning(head);
        return;
    }

    Node* temp = head;
    int currentPosition = 1;

    while (temp != nullptr && currentPosition < position) {
        temp = temp->next;
        currentPosition++;
    }

    if (temp == nullptr) {
        cout << "Position out of bounds.\n";
        return;
    }

    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    }
    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }

    delete temp;
}

// Function to display the Doubly Linked List
void displayList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Main function to test the insertion and deletion
int main() {
    Node* head = nullptr; // Initialize an empty Doubly Linked List

    // Test insertions
    insertAtBeginning(head, 10);
    insertAtEnd(head, 20);
    insertAtPosition(head, 2, 15);
    cout << "Doubly Linked List after insertions: ";
    displayList(head);

    // Test deletions
    deleteAtPosition(head, 2);
    cout << "After deleting at position 2: ";
    displayList(head);

    deleteAtBeginning(head);
    cout << "After deleting at beginning: ";
    displayList(head);

    deleteAtEnd(head);
    cout << "After deleting at end: ";
    displayList(head);

    return 0;
}
