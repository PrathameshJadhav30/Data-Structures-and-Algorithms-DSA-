#include <iostream>
using namespace std;

// Define a Node for the Circular Linked List
class Node {
public:
    int data;    // Data part of the Node
    Node* next;  // Pointer to the next Node

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Function to create a Circular Linked List with n nodes
Node* createCircularLinkedList(int n) {
    if (n <= 0) {
        cout << "Number of nodes must be greater than 0.\n";
        return nullptr;
    }

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 1; i <= n; i++) {
        Node* newNode = new Node(i);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            newNode->next = head; // Point to itself for circularity
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head; // Maintain circularity
        }
    }

    return head;
}

// Function to insert a node at a specific position in the Circular Linked List
void insertInCircularList(Node*& head, int position, int value) {
    Node* newNode = new Node(value);

    // If the list is empty
    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
        return;
    }

    // If inserting at the head (position 1)
    if (position == 1) {
        Node* tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }
        newNode->next = head;
        tail->next = newNode;
        head = newNode;
        return;
    }

    Node* temp = head;
    int currentPosition = 1;

    // Traverse to the node just before the desired position
    while (temp->next != head && currentPosition < position - 1) {
        temp = temp->next;
        currentPosition++;
    }

    // Insert the new node at the specified position
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

// Main function to test Circular Linked List insertion
int main() {
    int n, position, value;
    cout << "Enter the number of nodes for the Circular Linked List: ";
    cin >> n;

    Node* head = createCircularLinkedList(n);

    cout << "Circular Linked List: ";
    displayCircularList(head);

    cout << "\nEnter the position to insert: ";
    cin >> position;
    cout << "Enter the value to insert: ";
    cin >> value;

    insertInCircularList(head, position, value);

    cout << "Circular Linked List after insertion: ";
    displayCircularList(head);

    return 0;
}
