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

// Main function to test Circular Linked List creation
int main() {
    int n;
    cout << "Enter the number of nodes for the Circular Linked List: ";
    cin >> n;

    Node* head = createCircularLinkedList(n);

    cout << "Circular Linked List: ";
    displayCircularList(head);

    return 0;
}
