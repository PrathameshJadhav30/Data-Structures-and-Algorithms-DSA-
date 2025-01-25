#include <iostream>
#include <queue> // Include the queue library to use the standard queue container
using namespace std;

// Function to insert an element into the queue
void insertElement(queue<int>& q, int value) {
    q.push(value); // Insert the element at the rear of the queue
    cout << "Inserted " << value << " into the queue." << endl;
}

// Function to display the front and rear elements of the queue
void displayFrontAndRear(queue<int>& q) {
    if (!q.empty()) {
        cout << "Front element: " << q.front() << endl; // The first element in the queue
        cout << "Rear element: " << q.back() << endl;   // The most recently added element
    } else {
        cout << "The queue is empty." << endl;
    }
}

// Function to display the size of the queue
void displaySize(queue<int>& q) {
    cout << "Current queue size: " << q.size() << endl;
}

// Main function
int main() {
    // Declare a queue of integers
    queue<int> q;

    
    // Insert elements into the queue using the function
    insertElement(q, 10); // Insert 10
    insertElement(q, 20); // Insert 20
    insertElement(q, 30); // Insert 30

    // Display the front and rear elements of the queue
    displayFrontAndRear(q);

    // Display the size of the queue
    displaySize(q);

    return 0;
}
