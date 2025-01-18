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

// Function to delete a node from a Circular Linked List at a specific position
void deleteNode(Node*& head, int position) {
    if (head == nullptr) {
        cout << "The list is empty. Nothing to delete.\n";
        return;
    }

    // Case 1: Deleting the head node
    if (position == 1) {
        Node* tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }

        // If there is only one node in the list
        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            tail->next = head->next;
            head = head->next;
            delete temp;
        }
        return;
    }

    // Case 2: Deleting a node at a specific position
    Node* temp = head;
    int count = 1;

    // Traverse to the (position - 1)th node
    while (count < position - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    // If the position is invalid
    if (temp->next == head || count != position - 1) {
        cout << "Invalid position. No node deleted.\n";
        return;
    }

    Node* delNode = temp->next;
    temp->next = delNode->next;
    delete delNode;
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

// Main function to test deletion in the Circular Linked List
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

    // Test Deletion
    int position;
    cout << "Enter the position to delete: ";
    cin >> position;

    deleteNode(head, position);

    cout << "Circular Linked List after deletion: ";
    displayCircularList(head);

    return 0;
}
