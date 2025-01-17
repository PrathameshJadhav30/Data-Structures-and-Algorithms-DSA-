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

// Function to insert a node in the middle of the Doubly Linked List
void insertInMiddle(Node*& head, int position, int value) {
    if (position <= 1) {
        cout << "Position must be greater than 1 for middle insertion.\n";
        return;
    }

    Node* newNode = new Node(value);
    Node* temp = head;
    int currentPosition = 1;

    while (temp != nullptr && currentPosition < position - 1) {
        temp = temp->next;
        currentPosition++;
    }

    if (temp == nullptr || temp->next == nullptr) {
        cout << "Position out of bounds.\n";
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
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

// Main function to test the middle insertion
int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->prev = head;
    head->next->next = new Node(30);
    head->next->next->prev = head->next;

    cout << "Original Doubly Linked List: ";
    displayList(head);

    // Insert in the middle
    insertInMiddle(head, 2, 15);
    cout << "After inserting 15 at position 2: ";
    displayList(head);

    insertInMiddle(head, 4, 25);
    cout << "After inserting 25 at position 4: ";
    displayList(head);

    return 0;
}
