#include <iostream>
#define MAX_SIZE 100 // Maximum size of the queue

using namespace std;

class CircularQueue {
private:
    int front, rear;           // Pointers for front and rear of the queue
    int arr[MAX_SIZE];         // Array to store queue elements

public:
    // Constructor to initialize the queue
    CircularQueue() {
        front = -1;            // Indicates the queue is initially empty
        rear = -1;             // Indicates the queue is initially empty
    }

    // Function to check if the queue is full
    bool isFull() {
        // Queue is full if rear wraps around and meets front
        return (front == 0 && rear == MAX_SIZE - 1) || (rear == (front - 1) % (MAX_SIZE - 1));
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1;    // Queue is empty if front is -1
    }

    // Function to add an element to the queue
    void enQueue(int value) {
        if (isFull()) {
            // Queue is full, cannot add more elements
            cout << "Queue is full." << endl;
            return;
        }

        if (front == -1) {
            // First element being added to the queue
            front = 0;
        }

        // Increment rear in a circular manner and add the element
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = value;
        cout << "Enqueued element: " << value << endl;
    }

    // Function to remove an element from the queue
    int deQueue() {
        if (isEmpty()) {
            // Queue is empty, cannot remove any elements
            cout << "Queue is empty." << endl;
            return -1;
        }

        // Retrieve the front element
        int element = arr[front];
        
        if (front == rear) {
            // Queue becomes empty after removing the last element
            front = -1;
            rear = -1;
        } else {
            // Increment front in a circular manner
            front = (front + 1) % MAX_SIZE;
        }

        cout << "Dequeued element: " << element << endl;
        return element;
    }

    // Function to display the elements in the queue
    void display() {
        if (isEmpty()) {
            // Queue is empty, nothing to display
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Elements in the queue: ";

        // Traverse the queue from front to rear in a circular manner
        int i;
        for (i = front; i != rear; i = (i + 1) % MAX_SIZE) {
            cout << arr[i] << " ";
        }
        cout << arr[i] << endl; // Print the last element
    }
};

int main() {
    CircularQueue q;

    // Add elements to the queue
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);

    // Display the queue
    q.display();

    // Remove elements from the queue
    q.deQueue();
    q.deQueue();

    // Display the queue after dequeuing
    q.display();

    // Add more elements to the queue
    q.enQueue(50);
    q.enQueue(60);

    // Display the final state of the queue
    q.display();

    return 0;
}
