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

// Function to insert a node at the nth position in the Circular Linked List
void insertAtNthPosition(Node*& head, int value, int position) {
    Node* newNode = new Node(value);

    // If inserting at the head (position 1)
    if (position == 1) {
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* tail = head;
            while (tail->next != head) {
                tail = tail->next;
            }
            newNode->next = head;
            tail->next = newNode;
            head = newNode;
        }
        return;
    }

    // Traverse to the (position-1)th node
    Node* temp = head;
    int count = 1;
    while (count < position - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    // Insert the new node at the nth position
    newNode->next = temp->next;
    temp->next = newNode;
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

// Main function to test insertion at nth position
int main() {
    Node* head = nullptr; // Initialize an empty Circular Linked List

    int n, value, position;
    cout << "How many nodes do you want to insert? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << (i + 1) << ": ";
        cin >> value;
        cout << "Enter position for node " << (i + 1) << ": ";
        cin >> position;

        insertAtNthPosition(head, value, position);

        cout << "Circular Linked List after insertion: ";
        displayCircularList(head);
    }

    return 0;
}
