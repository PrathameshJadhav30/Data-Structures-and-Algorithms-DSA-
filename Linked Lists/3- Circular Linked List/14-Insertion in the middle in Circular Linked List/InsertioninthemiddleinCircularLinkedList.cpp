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

// Function to insert a node in the middle of the Circular Linked List
void insertInMiddle(Node*& head, int value) {
    if (head == nullptr) {
        cout << "The list is empty. Inserting at the beginning.\n";
        head = new Node(value);
        head->next = head;
        return;
    }

    Node* newNode = new Node(value);
    Node* slow = head;
    Node* fast = head;

    // Traverse to find the middle node using slow and fast pointers
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Insert the new node after the middle node
    newNode->next = slow->next;
    slow->next = newNode;
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

// Main function to test insertion in the middle
int main() {
    Node* head = nullptr;

    // Insert nodes in the Circular Linked List
    insertInMiddle(head, 10);  // Insert 10
    insertInMiddle(head, 20);  // Insert 20
    insertInMiddle(head, 30);  // Insert 30
    insertInMiddle(head, 40);  // Insert 40

    // Display the Circular Linked List after insertion
    cout << "Circular Linked List after insertion in the middle: ";
    displayCircularList(head);

    return 0;
}
