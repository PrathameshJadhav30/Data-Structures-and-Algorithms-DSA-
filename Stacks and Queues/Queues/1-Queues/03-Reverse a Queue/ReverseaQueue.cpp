#include <bits/stdc++.h>
using namespace std;

// Function to reverse a queue using recursion
void Reverse_Queue_using_Recursion(queue<long long int> &q) {
    // Base condition: If queue has only one element, no further processing is needed
    if (q.size() == 1)
        return;

    // Store the front element of the queue
    int frontElement = q.front();
    // Remove the front element
    q.pop();
    // Recursively reverse the remaining queue
    Reverse_Queue_using_Recursion(q);
    // Add the stored element back to the end of the queue
    q.push(frontElement);
}

// Function to display the elements of a queue
void Show(queue<long long int> &q) {
    // Create a copy of the queue to preserve the original queue
    queue<long long int> tempQueue = q;
    // Loop through the copy and print each element
    while (!tempQueue.empty()) {
        cout << tempQueue.front() << " "; // Print the front element
        tempQueue.pop(); // Remove the printed element
    }
}

int main() {
    queue<long long int> q; // Declare a queue of long long integers

    // Push elements into the queue
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    // Display the queue before reversal
    cout << "At first, the queue is: ";
    Show(q);
    cout << endl;

    // Reverse the queue using recursion
    Reverse_Queue_using_Recursion(q);

    // Display the queue after reversal
    cout << "After reversing the queue using recursion, the queue is: ";
    Show(q);
    cout << endl;

    return 0;
}
