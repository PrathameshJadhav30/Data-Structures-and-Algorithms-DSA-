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

// Function to display the Doubly Linked List
void displayList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Main function to test the deletion from the beginning
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

    
    return 0;
}
