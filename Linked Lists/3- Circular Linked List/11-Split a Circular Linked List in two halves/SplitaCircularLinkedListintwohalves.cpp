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

// Function to split the Circular Linked List into two halves
void splitCircularList(Node* head, Node*& head1, Node*& head2) {
    if (head == nullptr || head->next == head) {
        cout << "List is too small to split.\n";
        return;
    }

    Node* slow = head;
    Node* fast = head;

    // Use slow and fast pointer technique to find the middle
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Set the head of the first half
    head1 = head;

    // Set the head of the second half
    if (fast->next->next == head) {
        fast = fast->next; // Move fast to the last node
    }
    head2 = slow->next;

    // Break the list into two halves
    slow->next = head1;
    fast->next = head2;
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

// Main function to test the split operation
int main() {
    // Create a Circular Linked List manually
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = head;

    cout << "Original Circular Linked List: ";
    displayCircularList(head);

    Node* head1 = nullptr;
    Node* head2 = nullptr;

    // Split the Circular Linked List into two halves
    splitCircularList(head, head1, head2);

    cout << "First Half: ";
    displayCircularList(head1);

    cout << "Second Half: ";
    displayCircularList(head2);

    return 0;
}
