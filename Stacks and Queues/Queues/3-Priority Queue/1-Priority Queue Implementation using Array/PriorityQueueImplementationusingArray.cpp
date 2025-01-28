#include <iostream>
using namespace std;

struct PriorityQueue {
    int size;     // Maximum size of the priority queue
    int* arr;     // Array to store elements
    int count;    // Current number of elements

    // Constructor to initialize the priority queue
    PriorityQueue(int maxSize) {
        size = maxSize;
        arr = new int[size];
        count = 0;
    }

    // Function to insert an element into the priority queue
    void insert(int element) {
        if (count == size) {
            cout << "Priority Queue is full!" << endl;
            return;
        }

        int i;
        // Find the correct position for the element based on priority
        for (i = count - 1; i >= 0 && arr[i] > element; i--) {
            arr[i + 1] = arr[i];
        }

        arr[i + 1] = element; // Insert the element
        count++;
    }

    // Function to remove the element with the highest priority (lowest value)
    void remove() {
        if (isEmpty()) {
            cout << "Priority Queue is empty!" << endl;
            return;
        }
        count--; // Simply decrease the count to remove the smallest element
    }

    // Function to get the element with the highest priority
    int peek() {
        if (isEmpty()) {
            cout << "Priority Queue is empty!" << endl;
            return -1;
        }
        return arr[0]; // The smallest element is at the front
    }

    // Function to check if the priority queue is empty
    bool isEmpty() {
        return count == 0;
    }

    // Destructor to clean up memory
    ~PriorityQueue() {
        delete[] arr;
    }
};

int main() {
    PriorityQueue pq(5);

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
