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

// Function to delete a node from the end of the Doubly Linked List
void deleteAtEnd(Node*& head) {
    if (head == nullptr) {
        cout << "The list is empty.\n";
        return;
    }

    // If there's only one node in the list
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    // Traverse to the last node
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // Delete the last node
    temp->prev->next = nullptr;
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

// Main function to test the deletion from the end
int main() {
    Node* head = nullptr; // Initialize an empty Doubly Linked List

    // Insert some nodes for testing
    head = new Node(10);
    head->next = new Node(20);
    head->next->prev = head;
    head->next->next = new Node(30);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(40);
    head->next->next->next->prev = head->next->next;

    cout << "Original Doubly Linked List: ";
    displayList(head);

    // Test deletion at the end
    deleteAtEnd(head);
    cout << "After deleting from the end: ";
    displayList(head);

    deleteAtEnd(head);
    cout << "After deleting from the end again: ";
    displayList(head);

    deleteAtEnd(head);
    cout << "After deleting from the end again: ";
    displayList(head);

    deleteAtEnd(head);
    cout << "After deleting the last node: ";
    displayList(head);

    deleteAtEnd(head); // Attempt to delete from an empty list

    return 0;
}
