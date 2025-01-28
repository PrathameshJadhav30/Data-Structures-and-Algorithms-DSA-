#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;     // Priority value (smaller number = higher priority)
    Node* next;   // Pointer to the next node

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Priority Queue class
class PriorityQueue {
private:
    Node* head; // Pointer to the head of the linked list

public:
    // Constructor to initialize the priority queue
    PriorityQueue() {
        head = nullptr;
    }

    // Function to insert an element into the priority queue
    void insert(int element) {
        Node* newNode = new Node(element);

        // If the list is empty or the new element has the highest priority
        if (!head || head->data > element) {
            newNode->next = head;
            head = newNode;
            return;
        }

        // Traverse the list to find the correct position for the new element
        Node* temp = head;
        while (temp->next && temp->next->data <= element) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Function to remove the element with the highest priority
    void remove() {
        if (isEmpty()) {
            cout << "Priority Queue is empty!" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp; // Free memory of the removed node
    }

    // Function to get the element with the highest priority
    int peek() {
        if (isEmpty()) {
            cout << "Priority Queue is empty!" << endl;
            return -1;
        }
        return head->data;
    }

    // Function to check if the priority queue is empty
    bool isEmpty() {
        return head == nullptr;
    }

    // Destructor to free memory
    ~PriorityQueue() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    PriorityQueue pq;

    pq.insert(30);
    pq.insert(20);
    pq.insert(50);
    pq.insert(10);
    pq.insert(40);

    cout << "Element with highest priority: " << pq.peek() << endl;

    pq.remove();
    cout << "After removing, element with highest priority: " << pq.peek() << endl;

    return 0;
}
