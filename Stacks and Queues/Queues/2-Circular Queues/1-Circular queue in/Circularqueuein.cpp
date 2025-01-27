#include <iostream>
#include <climits> // Include for INT_MIN
using namespace std;

// Structure defining a Circular Queue
struct Queue {
    int rear, front; // Pointers for the rear and front of the queue
    int size;        // Maximum size of the queue
    int* arr;        // Dynamic array to store queue elements

    // Constructor to initialize the queue
    Queue(int s) {
        front = rear = -1; // Initially, the queue is empty
        size = s;          // Set the size of the queue
        arr = new int[s];  // Dynamically allocate memory for the queue
    }

    // Method to insert an element into the queue
    void enQueue(int value);

    // Method to remove an element from the queue
    int deQueue();

    // Method to display the current elements in the queue
    void displayQueue();
};

// Function to add an element to the Circular Queue
void Queue::enQueue(int value) {
    // Check if the queue is full
    if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1))) {
        cout << "\nQueue is Full";
        return;
    }

    // If the queue is empty, initialize front and rear
    if (front == -1) {
        front = rear = 0;
        arr[rear] = value;
    }
    // Wrap around the rear pointer if it reaches the end
    else if (rear == size - 1 && front != 0) {
        rear = 0;
        arr[rear] = value;
    }
    // Normal case: Increment rear and insert the element
    else {
        rear++;
        arr[rear] = value;
    }
}

// Function to remove an element from the Circular Queue
int Queue::deQueue() {
    // Check if the queue is empty
    if (front == -1) {
        cout << "\nQueue is Empty";
        return INT_MIN;
    }

    int data = arr[front]; // Retrieve the front element
    arr[front] = -1;       // Optional: Reset the dequeued position

    // If the queue becomes empty after this operation
    if (front == rear) {
        front = rear = -1;
    }
    // Wrap around the front pointer if it reaches the end
    else if (front == size - 1) {
        front = 0;
    }
    // Normal case: Increment the front pointer
    else {
        front++;
    }

    return data;
}

// Function to display the elements in the Circular Queue
void Queue::displayQueue() {
    // Check if the queue is empty
    if (front == -1) {
        cout << "\nQueue is Empty";
        return;
    }

    cout << "\nElements in Circular Queue are: ";

    // If rear is ahead or equal to front
    if (rear >= front) {
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
    }
    // If the queue is wrapped around
    else {
        for (int i = front; i < size; i++) {
            cout << arr[i] << " ";
        }
        for (int i = 0; i <= rear; i++) {
            cout << arr[i] << " ";
        }
    }
}

// Driver code to demonstrate the Circular Queue
int main() {
    Queue q(5); // Create a queue with size 5

    // Insert elements into the queue
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);

    // Display the elements in the queue
    q.displayQueue();

    // Remove elements from the queue
    cout << "\nDeleted value = " << q.deQueue();
    cout << "\nDeleted value = " << q.deQueue();

    // Display the queue after deletions
    q.displayQueue();

    // Insert more elements into the queue
    q.enQueue(50);
    q.enQueue(60);
    q.enQueue(70);

    // Display the final state of the queue
    q.displayQueue();

    return 0;
}
