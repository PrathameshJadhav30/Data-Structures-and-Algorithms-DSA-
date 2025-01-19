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

// Function to insert a node at the beginning
void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }

    newNode->next = head;
    tail->next = newNode;
    head = newNode;
}

// Function to insert a node at the end
void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }

    tail->next = newNode;
    newNode->next = head;
}

// Function to delete the first node
void deleteFromBeginning(Node*& head) {
    if (head == nullptr) {
        cout << "The list is empty. Nothing to delete.\n";
        return;
    }

    if (head->next == head) {
        delete head;
        head = nullptr;
        return;
    }

    Node* tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }

    Node* temp = head;
    tail->next = head->next;
    head = head->next;
    delete temp;
}

// Function to delete the last node
void deleteFromEnd(Node*& head) {
    if (head == nullptr) {
        cout << "The list is empty. Nothing to delete.\n";
        return;
    }

    if (head->next == head) {
        delete head;
        head = nullptr;
        return;
    }

    Node* current = head;
    Node* prev = nullptr;

    while (current->next != head) {
        prev = current;
        current = current->next;
    }

    prev->next = head;
    delete current;
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

// Main function to test insertion and deletion
int main() {
    Node* head = nullptr;

    // Test Insertion
    cout << "Inserting at the beginning: 10, 20\n";
    insertAtBeginning(head, 10);
    insertAtBeginning(head, 20);
    displayCircularList(head);

    cout << "Inserting at the end: 30, 40\n";
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);
    displayCircularList(head);

    // Test Deletion
    cout << "Deleting from the beginning:\n";
    deleteFromBeginning(head);
    displayCircularList(head);

    cout << "Deleting from the end:\n";
    deleteFromEnd(head);
    displayCircularList(head);

    return 0;
}
