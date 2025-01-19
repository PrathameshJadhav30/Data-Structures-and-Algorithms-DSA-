#include <iostream>
using namespace std;

// Define a Node for the Circular Linked List
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Function to delete the last node from the Circular Linked List
void deleteFromEnd(Node*& head) {
    if (head == nullptr) {
        cout << "The list is empty. Nothing to delete.\n";
        return;
    }

    // Case 1: If the list has only one node
    if (head->next == head) {
        delete head;
        head = nullptr;
        return;
    }

    // Case 2: If the list has multiple nodes
    Node* current = head;
    Node* prev = nullptr;

    // Traverse to the last node
    while (current->next != head) {
        prev = current;
        current = current->next;
    }

    prev->next = head; // Update the second last node's next pointer
    delete current;    // Delete the last node
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

// Main function to test deletion from the end
int main() {
    Node* head = nullptr;

    // Create a Circular Linked List manually for testing
    head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = head;

    cout << "Original Circular Linked List: ";
    displayCircularList(head);

    // Delete the last node
    deleteFromEnd(head);

    cout << "Circular Linked List after deletion from end: ";
    displayCircularList(head);

    return 0;
}
