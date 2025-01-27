#include <iostream>
using namespace std;

// Node class representing a single element in the Circular Queue
class Node {
public:
    int data;      // Data stored in the node
    Node* next;    // Pointer to the next node
};

// CircularQueue class to manage the operations of a circular queue using a linked list
class CircularQueue {
private:
    Node* front;   // Pointer to the front of the queue
    Node* rear;    // Pointer to the rear of the queue

public:
    // Constructor to initialize an empty queue
    CircularQueue() {
        front = rear = nullptr;
    }

    // Function to add an element to the queue
    void enqueue(int data) {
        Node* newNode = new Node(); // Create a new node
        newNode->data = data;
        newNode->next = nullptr;

        if (front == nullptr) {
            // If the queue is empty, set front and rear to the new node
            front = rear = newNode;
            rear->next = front; // Make it circular
        } else {
            // Otherwise, add the new node at the rear and update the links
            rear->next = newNode;
            rear = newNode;
            rear->next = front; // Maintain the circular link
        }

        cout << data << " has been enqueued." << endl;
    }

    // Function to remove an element from the queue
    void dequeue() {
        if (front == nullptr) {
            // If the queue is empty
            cout << "Queue is empty." << endl;
            return;
        }

        if (front == rear) {
            // If there's only one element in the queue
            Node* temp = front;
            front = rear = nullptr;
            delete temp; // Free the memory of the removed node
        } else {
            // For more than one element, remove the front node and update links
            Node* temp = front;
            front = front->next;
            rear->next = front; // Maintain the circular link
            delete temp; // Free the memory of the removed node
        }

        cout << "Dequeued an element." << endl;
    }

    // Function to display the elements in the queue
    void display() {
        if (front == nullptr) {
            // If the queue is empty
            cout << "Queue is empty." << endl;
            return;
        }

        // Traverse the queue and print all elements
        Node* temp = front;
        cout << "Circular Queue: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front); // Stop when the circular link completes
        cout << endl;
    }
};

// Main function to demonstrate the Circular Queue operations
int main() {
    CircularQueue q;

    // Enqueue elements into the queue
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display(); // Display the queue

    // Dequeue elements from the queue
    q.dequeue();
    q.dequeue();
    q.display(); // Display the queue after dequeuing

    // Enqueue more elements
    q.enqueue(50);
    q.enqueue(60);
    q.display(); // Display the final state of the queue

    return 0;
}
