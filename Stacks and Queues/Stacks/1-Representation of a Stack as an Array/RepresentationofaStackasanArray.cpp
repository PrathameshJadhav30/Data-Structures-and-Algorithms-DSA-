#include<bits/stdc++.h>
using namespace std;

// Stack class definition using an array
class Stack {
    public:
    int top;        // To track the top of the stack
    int maxSize;    // Maximum size of the stack
    int* array;     // Pointer to dynamically allocated array for the stack

    // Constructor to initialize the stack with a given size
    Stack(int max) {
        top = -1;             // Initialize top as -1 (stack is empty initially)
        maxSize = max;        // Set maximum size of the stack
        array = new int[max]; // Dynamically allocate memory for the stack array
    }

    // Function to check if the stack is full
    int isFull() {
        if (top == maxSize - 1) {
            cout << "Will not be able to push, maxSize reached" << endl;
        }
        return top == maxSize - 1;  // Return true if stack is full
    }

    // Function to check if the stack is empty
    int isEmpty() {
        if (top == -1) {
            cout << "Will not be able to pop, stack is empty" << endl;
        }
        return top == -1;  // Return true if stack is empty
    }

    // Function to push an item onto the stack
    void push(int item) {
        if (isFull()) return; // If stack is full, do not push
        array[++top] = item;  // Increment top and insert item
        cout << "We have pushed " << item << " to stack" << endl;
    }

    // Function to pop an item from the stack
    int pop() {
        if (isEmpty()) return INT_MIN; // If stack is empty, return an invalid value
        return array[top--];  // Return the top element and decrement top
    }

    // Function to get the top item of the stack without popping
    int peek() {
        if (isEmpty()) return INT_MIN; // If stack is empty, return an invalid value
        return array[top];  // Return the top element
    }
};

int main() {
    Stack stack(10); // Create a stack with a max size of 10
    stack.push(5);   // Push elements onto the stack
    stack.push(10);
    stack.push(15);

    int flag = 1;
    while (flag) {
        if (!stack.isEmpty()) { // Check if stack is not empty
            cout << "We have popped " << stack.pop() << " from stack" << endl;
        } else {
            cout << "Can't pop, stack must be empty\n";
        }
        flag = 0;  // Set flag to 0 to exit the loop
    }

    return 0;
}
