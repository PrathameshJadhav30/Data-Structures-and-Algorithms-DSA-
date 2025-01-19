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

// Function to delete a node at the nth position in the Circular Linked List
void deleteAtNthPosition(Node*& head, int position) {
    if (head == nullptr) {
        cout << "The list is empty. Nothing to delete.\n";
        return;
    }

    // Case 1: Deleting the first node
    if (position == 1) {
        Node* tail = head;
        while (tail->next != head) { // Find the tail node
            tail = tail->next;
        }

        // If only one node exists
        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            tail->next = head->next; // Update tail's next pointer
            head = head->next;       // Move head pointer
            delete temp;
        }
        return;
    }

    // Case 2: Deleting at any other position
    Node* current = head;
    int count = 1;

    // Traverse to the (position-1)th node
    while (count < position - 1 && current->next != head) {
        current = current->next;
        count++;
    }

    // If position is invalid
    if (current->next == head || count != position - 1) {
        cout << "Invalid position. No node deleted.\n";
        return;
    }

    Node* delNode = current->next;  // Node to be deleted
    current->next = delNode->next;  // Update link to skip the deleted node
    delete delNode;                 // Free memory
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

// Main function to test deletion at nth position
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

    int position;
    cout << "Enter the position to delete: ";
    cin >> position;

    deleteAtNthPosition(head, position);

    cout << "Circular Linked List after deletion: ";
    displayCircularList(head);

    return 0;
}
