#include <bits/stdc++.h>
using namespace std;

// Queue class implemented using two stacks
class Queue {
public:
    stack<int> s1, s2; // s1 is the main stack, s2 is used for operations

    // Function to add an element to the queue
    void Push(int i) {
        cout << "Pushing the element: " << i << endl;
        s1.push(i);
    }

    // Function to remove the front element from the queue
    int pop() {
        if (s1.empty()) {
            cout << "The queue is empty" << endl;
            return -1;
        }

        // Transfer elements from s1 to s2 to reverse the order
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Remove the front element (top of s2)
        int frontElement = s2.top();
        s2.pop();
        cout << "Popping the element: " << frontElement << endl;

        // Transfer elements back to s1 to maintain queue order
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }

        return frontElement;
    }

    // Function to display all elements in the queue
    void Show() {
        if (s1.empty()) {
            cout << "The queue is empty" << endl;
            return;
        }

        // Transfer elements from s1 to s2 to reverse the order for display
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Display the elements in the queue
        while (!s2.empty()) {
            cout << s2.top() << " ";
            s1.push(s2.top()); // Restore elements back to s1
            s2.pop();
        }
        cout << endl;
    }

    // Function to get the front element of the queue
    int front() {
        if (s1.empty()) {
            cout << "The queue is empty" << endl;
            return -1;
        }

        // Transfer elements from s1 to s2 to access the front element
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Get the front element (top of s2)
        int frontElement = s2.top();

        // Transfer elements back to s1 to maintain queue order
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }

        return frontElement;
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
    cout << "The Queue now is: ";
    q.Show();

    // Get and display the front element
    cout << "The front value right now is: " << q.front() << endl;

    // Remove elements from the queue
    q.pop();
    q.pop();

    // Add more elements to the queue
    q.Push(12);
    q.Push(8);

    // Get and display the front element again
    cout << "The front value right now is: " << q.front() << endl;

    // Display the queue again
    cout << "The Queue now is: ";
    q.Show();

    return 0;
}
