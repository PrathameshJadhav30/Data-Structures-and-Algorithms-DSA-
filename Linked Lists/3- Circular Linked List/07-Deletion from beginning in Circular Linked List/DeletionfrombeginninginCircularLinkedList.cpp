#include <iostream>
using namespace std;

// Define a Node for the Circular Linked List
class Node {
public:
    int data;    // Data part of the Node
    Node* next;  // Pointer to the next Node

    // Constructor to initialize a new node
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Function to delete the first node from the Circular Linked List
void deleteFromBeginning(Node*& head) {
    if (head == nullptr) {
        cout << "The list is empty. Nothing to delete.\n";
        return;
    }

    // Case 1: If there is only one node in the list
    if (head->next == head) {
        delete head;
        head = nullptr;
        return;
    }

    // Case 2: If there are multiple nodes
    Node* tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }

    Node* temp = head;
    tail->next = head->next; // Update the last node's `next` to the new head
    head = head->next;       // Move the head pointer to the next node
    delete temp;             // Delete the old head
}

// Function to display the Circular Linked List
void displayCircularList(Node* head) {
    if (head == nullptr) {
        cout << "The list is empty.\n";
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

// Main function to test deletion from the beginning
int main() {
    Node* head = nullptr;

    // Create a Circular Linked List manually for testing
    head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    head->next = second;
    second->next = third;
    third->next = head;

    cout << "Original Circular Linked List: ";
    displayCircularList(head);

    // Delete the first node
    deleteFromBeginning(head);

    cout << "Circular Linked List after deletion from beginning: ";
    displayCircularList(head);

    return 0;
}
