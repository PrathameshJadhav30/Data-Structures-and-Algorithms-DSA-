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
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    if (temp->prev != nullptr) {
        temp->prev->next = nullptr;
    } else {
        head = nullptr; // If there was only one node
    }
    delete temp;
}

// Function to delete a node at a given position in the Doubly Linked List
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

    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
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

// Main function to test the deletion
int main() {
    Node* head = nullptr; // Initialize an empty Doubly Linked List

    // Insert some nodes for testing
    head = new Node(10);
    head->next = new Node(20);
    head->next->prev = head;
    head->next->next = new Node(30);
    head->next->next->prev = head->next;

    cout << "Original Doubly Linked List: ";
    displayList(head);

    // Test deletion at beginning
    deleteAtBeginning(head);
    cout << "After deleting at beginning: ";
    displayList(head);

    // Test deletion at end
    deleteAtEnd(head);
    cout << "After deleting at end: ";
    displayList(head);

    // Test deletion at position
    deleteAtPosition(head, 1);
    cout << "After deleting at position 1: ";
    displayList(head);

    deleteAtPosition(head, 5); // Attempt to delete out-of-bounds

    return 0;
}
