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

// Function to insert a node in sorted order
void sortedInsert(Node*& head, int value) {
    Node* newNode = new Node(value);

    // Case 1: If the list is empty
    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* current = head;
    Node* prev = nullptr;

    // Case 2: If the new node is smaller than the head node
    if (value <= head->data) {
        newNode->next = head;

        // Find the last node and update its next pointer
        while (current->next != head) {
            current = current->next;
        }
        current->next = newNode;

        head = newNode;
        return;
    }

    // Case 3: Traverse the list and find the appropriate position for insertion
    do {
        prev = current;
        current = current->next;
    } while (current != head && current->data < value);

    prev->next = newNode;
    newNode->next = current;
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

// Main function to test the sorted insert operation
int main() {
    Node* head = nullptr;

    // Insert nodes in sorted order
    sortedInsert(head, 30);
    sortedInsert(head, 10);
    sortedInsert(head, 50);
    sortedInsert(head, 20);
    sortedInsert(head, 40);

    // Display the Circular Linked List after sorted insertions
    cout << "Circular Linked List after sorted insertions: ";
    displayCircularList(head);

    return 0;
}
