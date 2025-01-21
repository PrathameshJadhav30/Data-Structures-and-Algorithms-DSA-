#include<bits/stdc++.h>
using namespace std;

// Class to implement stack using an array
class Stack {
    public:
    int top;        // Keeps track of the top of the stack
    int maxSize;    // Maximum size of the stack
    int* array;     // Pointer to the array that stores the stack elements

    // Constructor to initialize stack with a given maximum size
    Stack(int max) {
        top = -1;             // Stack is initially empty, so top is -1
        maxSize = max;        // Set the maximum size of the stack
        array = new int[max]; // Dynamically allocate memory for the stack array
    }

    // Function to check if the stack is full
    int isFull() {
        if (top == maxSize - 1) { // If top is at the last index, the stack is full
            cout << "Will not be able to push, maxSize reached" << endl;
        }
        return top == maxSize - 1; // Returns true if stack is full
    }

    // Function to check if the stack is empty
    int isEmpty() {
        if (top == -1) { // If top is -1, the stack is empty
            cout << "Will not be able to pop, stack is empty" << endl;
        }
        return top == -1; // Returns true if stack is empty
    }

    // Function to push an item onto the stack
    void push(int item) {
        if (isFull()) return; // If the stack is full, do not push the item
        array[++top] = item;  // Increment top and insert the item
        cout << "We have pushed " << item << " to stack" << endl;
    }

    // Function to pop an item from the stack
    int pop() {
        if (isEmpty()) return INT_MIN; // If the stack is empty, return a value indicating failure
        return array[top--];  // Return the item at the top and decrement top
    }

    // Function to view the top item without removing it
    int peek() {
        if (isEmpty()) return INT_MIN; // If the stack is empty, return an invalid value
        return array[top]; // Return the top element of the stack
    }
};

int main() {
    Stack stack(10); // Create a stack with a maximum size of 10

    // Push elements onto the stack
    stack.push(5);
    stack.push(10);
    stack.push(15);

    int flag = 1;  // Control flag for the while loop
    while (flag) {
        if (!stack.isEmpty()) {  // If the stack is not empty, pop and print the element
            cout << "We have popped " << stack.pop() << " from stack" << endl;
        } else {  // If the stack is empty, display a message
            cout << "Can't pop, stack must be empty\n";
        }
        flag = 0;  // Stop the loop after one iteration
    }

    return 0;
}
