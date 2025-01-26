#include <iostream>
using namespace std;

// Define a class to represent a Node in the linked list
class Node {
public:
    int data;  // Data stored in the node
    Node *next; // Pointer to the next node
};

// Function to add an element to the front of the queue
void enqueue(Node **head, int data) {
    // Create a new node
    Node *new_node = new Node();

    // Assign the data to the new node
    new_node->data = data;

    // Set the new node's next pointer to the current head
    new_node->next = *head;

    // Update the head pointer to the new node
    *head = new_node;
}

// Function to remove an element from the front of the queue
void dequeue(Node **head) {
    // Temporary pointer to store the current head
    Node *temp = *head;

    // If the queue is empty, print a message and return
    if (*head == NULL) {
        cout << "Linked List Empty, nothing to delete" << endl;
        return;
    }

    // Move the head pointer to the next node
    *head = (*head)->next;

    // Free the memory of the removed node
    delete temp;
}

// Function to display the elements in the queue
void display(Node *node) {
    // Traverse the linked list until the end
    while (node != NULL) {
        // Print the data of the current node
        cout << node->data << " ";
        node = node->next; // Move to the next node
    }
    cout << endl;
}

int main() {
    Node *head = NULL; // Initialize the head pointer to NULL

    // Add elements to the queue
    enqueue(&head, 10);
    enqueue(&head, 11);
    enqueue(&head, 12);
    enqueue(&head, 13);
    enqueue(&head, 14);
    enqueue(&head, 15);
    enqueue(&head, 16);
    enqueue(&head, 17);
    enqueue(&head, 18);

    // Display the queue before deletion
    cout << "Queue before deletion: ";
    display(head);

    // Remove the front element of the queue
    dequeue(&head);

    // Display the queue after deletion
    cout << endl << "Queue after deletion: ";
    display(head);

    return 0;
}
