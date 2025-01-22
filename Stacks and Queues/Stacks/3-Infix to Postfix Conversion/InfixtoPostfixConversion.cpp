#include <iostream>
#include <stack>
#include <cctype> // For isalnum() to check if a character is alphanumeric
using namespace std;

// Function to define operator precedence
int precedence(char op) {
    if (op == '^') return 3;  // Highest precedence for exponentiation
    if (op == '*' || op == '/') return 2; // Multiplication and division
    if (op == '+' || op == '-') return 1; // Addition and subtraction
    return 0; // For non-operators
}

// Function to check if a character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Function to convert infix expression to postfix
string infixToPostfix(string infix) {
    stack<char> st;  // Stack to hold operators and parentheses
    string postfix = "";  // Resultant postfix expression

    // Loop through each character in the infix expression
    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        // If the character is an operand, add it to the postfix expression
        if (isalnum(ch)) {
            postfix += ch;
        }
        // If the character is an opening parenthesis, push it to the stack
        else if (ch == '(') {
            st.push(ch);
        }
        // If the character is a closing parenthesis
        else if (ch == ')') {
            // Pop from the stack until an opening parenthesis is found
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // Remove the opening parenthesis
        }
        // If the character is an operator
        else if (isOperator(ch)) {
            // Pop operators from the stack with greater or equal precedence
            while (!st.empty() && precedence(st.top()) >= precedence(ch)) {
                postfix += st.top();
                st.pop();
            }
            st.push(ch); // Push the current operator to the stack
        }
    }

    // Pop any remaining operators from the stack
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main() {
    // Input infix expression from the user
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    // Convert infix to postfix and display the result
    string postfix = infixToPostfix(infix);
    cout << "The postfix expression is: " << postfix << endl;

    return 0;
}
