#include <iostream>
using namespace std;

// Structure for a node in the priority queue
struct Node {
    int data;     // The value of the element
    int priority; // Priority of the element (lower value = higher priority)
    Node* next;   // Pointer to the next node

    Node(int d, int p) {
        data = d;
        priority = p;
        next = nullptr;
    }
};

// Priority Queue class
class PriorityQueue {
private:
    Node* head; // Pointer to the head of the queue

public:
    // Constructor to initialize the queue
    PriorityQueue() {
        head = nullptr;
    }

    // Function to insert an element into the priority queue
    void insert(int element, int priority) {
        Node* newNode = new Node(element, priority);

        // If the queue is empty or the new node has the highest priority
        if (!head || head->priority > priority) {
            newNode->next = head;
            head = newNode;
            return;
        }

        // Traverse the queue to find the correct position for the new node
        Node* temp = head;
        while (temp->next && temp->next->priority <= priority) {
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

    // Function to display the elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Priority Queue is empty!" << endl;
            return;
        }

        Node* temp = head;
        cout << "Priority Queue: ";
        while (temp) {
            cout << "[" << temp->data << ", Priority: " << temp->priority << "] -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
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

    pq.insert(30, 2); // Element 30 with priority 2
    pq.insert(20, 1); // Element 20 with priority 1
    pq.insert(50, 4); // Element 50 with priority 4
    pq.insert(10, 0); // Element 10 with priority 0
    pq.insert(40, 3); // Element 40 with priority 3

    pq.display();

    cout << "Element with highest priority: " << pq.peek() << endl;

    pq.remove();
    cout << "After removing the highest priority element:" << endl;
    pq.display();

    return 0;
}
