#include <bits/stdc++.h>
using namespace std;

// A class to implement a queue using a single stack with recursion
class Queue {
public:
    stack<int> s; // Stack to store the elements
    int size;     // Variable to keep track of the queue size

    // Constructor to initialize the queue
    Queue() {
        size = 0;
    }

    // Function to push an element into the queue
    void Push(int i) {
        cout << "Pushing the element: " << i << endl;
        s.push(i);
        size++;
    }

    // Function to pop the front element from the queue
    int pop() {
        if (size == 0) {
            cout << "The Queue is empty" << endl;
            return 0;
        }

        // Retrieve the top element of the stack
        int topElement = s.top();
        s.pop();

        // If the stack is not empty, recursively call pop to reach the bottom element
        if (!s.empty()) {
            int frontElement = pop(); // Recursive call
            s.push(topElement);       // Push the element back after the recursive call
            return frontElement;
        } else {
            // If the stack is empty, we reached the bottom element
            cout << "Popping " << topElement << endl;
            size--;
            return topElement;
        }
    }

    // Function to display the queue
    void display() {
        if (size == 0) {
            cout << "The Queue is empty" << endl;
            return;
        }

        // Retrieve and remove the top element
        int topElement = s.top();
        s.pop();

        // Recursively display the remaining elements
        if (!s.empty())
            display();

        // Print the current element
        cout << topElement << " ";

        // Push the element back to restore the stack
        s.push(topElement);
    }

    // Function to get the front element of the queue
    int front() {
        if (size == 0) {
            cout << "The Queue is empty" << endl;
            return 0;
        }

        // Retrieve the top element
        int topElement = s.top();
        s.pop();

        // If the stack is not empty, recursively call front to get the bottom element
        if (!s.empty()) {
            int frontElement = front();
            s.push(topElement); // Push the element back after the recursive call
            return frontElement;
        } else {
            // If the stack is empty, we reached the bottom element
            s.push(topElement);
            return topElement;
        }
    }

    // Function to check if the queue is empty
    bool empty() {
        return size == 0;
    }
};

int main() {
    Queue q;

    // Push elements into the queue
    q.Push(1);
    q.Push(5);
    q.Push(2);
    q.Push(11);

    // Display the queue
    q.display();
    cout << endl;

    // Get the front element
    cout << "The front-most value right now is: " << q.front() << endl;

    // Pop elements from the queue
    q.pop();
    q.pop();

    // Push new elements into the queue
    q.Push(12);
    q.Push(8);

    // Get the front element again
    cout << "The front-most value right now is: " << q.front() << endl;

    // Display the queue again
    q.display();
    cout << endl;

    return 0;
}
