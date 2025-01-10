#include <iostream>
using namespace std;

// Define the structure of a node in the linked list
struct Node {
    int data;
    Node* next;
};

// Function to delete a node at a given position in a singly linked list
void deleteNode(Node** head_ref, int position) {
    // Check if the linked list is empty
    if (*head_ref == nullptr)
        return;

    // Store head node
    Node* temp = *head_ref;

    // If head needs to be removed
    if (position == 0) {
        *head_ref = temp->next; // Change head
        delete temp;            // Free old head
        return;
    }

    // Find previous node of the node to be deleted
    for (int i = 0; temp != nullptr && i < position - 1; i++)
        temp = temp->next;

    // If position is more than number of nodes
    if (temp == nullptr || temp->next == nullptr)
        return;

    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    Node* next = temp->next->next;

    // Unlink the node from the linked list
    delete temp->next; // Free memory

    temp->next = next; // Unlink the deleted node from list
}

// Function to print the linked list
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Main function to test deletion
int main() {
    // Example usage
    Node* head = nullptr;

    // Inserting nodes into the linked list
    head = new Node({1, nullptr});
    head->next = new Node({2, nullptr});
    head->next->next = new Node({3, nullptr});
    head->next->next->next = new Node({4, nullptr});

    cout << "Original Linked List: ";
    printList(head);

    int position = 2; // Position of node to be deleted
    deleteNode(&head, position);

    cout << "Linked List after deletion at position " << position << ": ";
    printList(head);

    return 0;
}
