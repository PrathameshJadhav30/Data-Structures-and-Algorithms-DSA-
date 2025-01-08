// Using Class
#include <iostream>
using namespace std;

// Definition of a Node in the linked list
class Node {
public:
    int val;        // Value of the node
    Node *next;     // Pointer to the next node
};

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(Node **head, int val) {
    // Dynamically allocate memory for the new node
    Node *newNode = new Node();
    newNode->val = val;         // Assign value to the new node
    newNode->next = *head;      // Point new node's next to the current head
    *head = newNode;            // Update the head to the new node
    cout << val << " inserted at the beginning" << endl;
}

// Function to insert a node at the end of the linked list
void insertAtLast(Node **head, int val) {
    // Dynamically allocate memory for the new node
    Node *newNode = new Node();
    newNode->val = val;
    newNode->next = NULL;       // Last node always points to NULL

    // If the linked list is empty
    if (*head == NULL) {
        *head = newNode;
        cout << val << " inserted at the end" << endl;
        return;
    }

    // Traverse to the last node
    Node *tempNode = *head;
    while (tempNode->next != NULL)
        tempNode = tempNode->next;

    // Assign last node's next to the new node
    tempNode->next = newNode;
    cout << val << " inserted at the end" << endl;
}

// Function to get the current size of the linked list
int getCurrSize(Node *node) {
    int size = 0;
    while (node != NULL) {
        node = node->next;
        size++;
    }
    return size;
}

// Function to insert a node after the nth node in the linked list
void insertAfterNthNode(int n, int val, Node **head) {
    int size = getCurrSize(*head);

    // Validate position
    if (n < 0 || n > size) {
        cout << "Invalid position to insert" << endl;
        return;
    }

    // If inserting at the beginning
    if (n == 0) {
        insertAtBeginning(head, val);
        return;
    }

    // Dynamically allocate memory for the new node
    Node *newNode = new Node();
    newNode->val = val;
    newNode->next = NULL;

    // Traverse to the nth node
    Node *tempNode = *head;
    while (--n)
        tempNode = tempNode->next;

    // Update pointers to insert the new node
    newNode->next = tempNode->next;
    tempNode->next = newNode;

    cout << val << " inserted after position " << n + 1 << endl;
}

// Function to display the linked list
void display(Node *node) {
    cout << "Linked List: ";
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node *head = NULL; // Initialize head of the linked list

    // Insert elements at the beginning
    insertAtBeginning(&head, 12);
    insertAtBeginning(&head, 11);
    insertAtBeginning(&head, 10);
    display(head);

    // Insert elements at the end
    insertAtLast(&head, 13);
    insertAtLast(&head, 14);
    insertAtLast(&head, 16);
    display(head);

    // Insert elements at specific positions
    insertAfterNthNode(5, 15, &head); // Insert 15 after the 5th node
    insertAfterNthNode(0, 9, &head);  // Insert 9 at the beginning
    display(head);

    return 0;
}
