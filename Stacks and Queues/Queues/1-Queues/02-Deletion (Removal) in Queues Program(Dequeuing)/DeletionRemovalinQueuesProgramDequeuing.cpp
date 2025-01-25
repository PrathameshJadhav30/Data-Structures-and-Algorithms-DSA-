#include <iostream>
#include <queue> // Include the queue library to use the standard queue container
using namespace std;

// Function to insert an element into the queue
void insertElement(queue<int>& q, int value) {
    q.push(value); // Insert the element at the rear of the queue
    cout << "Inserted " << value << " into the queue." << endl;
}

// Function to delete an element from the queue
void deleteElement(queue<int>& q) {
    if (!q.empty()) {
        cout << "Removed " << q.front() << " from the queue." << endl;
        q.pop(); // Remove the element at the front of the queue
    } else {
        cout << "The queue is empty. Nothing to remove." << endl;
    }
}

// Function to display the front element of the queue
void displayFront(queue<int>& q) {
    if (!q.empty()) {
        cout << "Front element: " << q.front() << endl; // The first element in the queue
    } else {
        cout << "The queue is empty. No front element to display." << endl;
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

    // Insert elements into the queue
    insertElement(q, 10); // Insert 10
    insertElement(q, 20); // Insert 20
    insertElement(q, 30); // Insert 30

    // Display the front element and size of the queue
    displayFront(q);
    displaySize(q);

    // Perform deletion (removal) from the queue
    deleteElement(q); // Remove the first element (10)
    deleteElement(q); // Remove the next element (20)

    // Display the front element and size of the queue after deletions
    displayFront(q);
    displaySize(q);

    // Attempt to delete from an empty queue
    deleteElement(q); // Remove the last element (30)
    deleteElement(q); // Queue is now empty

    return 0;
}
