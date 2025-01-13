#include <iostream>
using namespace std;

// Node structure for the linked list
class Node {
public:
    int data;    // Data part of the node
    Node* next;  // Pointer to the next node

    Node(int value) { // Constructor to initialize a node
        data = value;
        next = nullptr;
    }
};

// Function to insert a new node at the end of the linked list
void append(Node** head, int value) {
    Node* newNode = new Node(value);
    if (*head == nullptr) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to display the linked list
void display(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Helper function to reverse a linked list starting from a given node
Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next;
    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Function to fold the linked list
void foldLinkedList(Node** head) {
    if (*head == nullptr || (*head)->next == nullptr) {
        return; // No need to fold if the list is empty or has only one element
    }

    // Step 1: Find the middle of the linked list
    Node* slow = *head;
    Node* fast = *head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse the second half of the linked list
    Node* secondHalf = reverse(slow->next);
    slow->next = nullptr; // Break the list into two halves

    // Step 3: Merge the two halves in a folded manner
    Node* firstHalf = *head;
    Node* temp1;
    Node* temp2;

    while (secondHalf != nullptr) {
        temp1 = firstHalf->next;
        temp2 = secondHalf->next;

        firstHalf->next = secondHalf;
        secondHalf->next = temp1;

        firstHalf = temp1;
        secondHalf = temp2;
    }
}

int main() {
    Node* head = nullptr; // Initialize an empty linked list

    // Example: Append some elements to the linked list
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);
    append(&head, 6);

    cout << "Original Linked List: \n";
    display(head);

    // Fold the linked list
    foldLinkedList(&head);

    cout << "Folded Linked List: \n";
    display(head);

    return 0;
}
