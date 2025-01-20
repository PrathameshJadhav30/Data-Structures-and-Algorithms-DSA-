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

// Function to count the number of nodes in the Circular Linked List
int countNodes(Node* head) {
    if (head == nullptr) {
        return 0;
    }

    int count = 0;
    Node* temp = head;

    do {
        count++;
        temp = temp->next;
    } while (temp != head);

    return count;
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

// Main function to test counting nodes
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

    // Count the number of nodes in the Circular Linked List
    int nodeCount = countNodes(head);
    cout << "Number of nodes in the Circular Linked List: " << nodeCount << endl;

    return 0;
}
