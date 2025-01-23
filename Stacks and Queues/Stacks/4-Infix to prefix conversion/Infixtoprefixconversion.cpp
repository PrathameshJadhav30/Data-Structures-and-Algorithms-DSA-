#include <iostream>
#include <stack>
#include <algorithm>
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

// Function to reverse a string
string reverseString(string str) {
    reverse(str.begin(), str.end());
    return str;
}

// Function to convert infix expression to prefix
string infixToPrefix(string infix) {
    // Reverse the infix expression
    string revInfix = reverseString(infix);

    // Replace '(' with ')' and vice versa
    for (int i = 0; i < revInfix.length(); i++) {
        if (revInfix[i] == '(') {
            revInfix[i] = ')';
        } else if (revInfix[i] == ')') {
            revInfix[i] = '(';
        }
    }

    stack<char> st;
    string prefix = "";

    // Loop through each character in the reversed infix expression
    for (int i = 0; i < revInfix.length(); i++) {
        char ch = revInfix[i];

        // If the character is an operand, add it to the prefix expression
        if (isalnum(ch)) {
            prefix += ch;
        }
        // If the character is an opening parenthesis, push it to the stack
        else if (ch == '(') {
            st.push(ch);
        }
        // If the character is a closing parenthesis
        else if (ch == ')') {
            // Pop from the stack until an opening parenthesis is found
            while (!st.empty() && st.top() != '(') {
                prefix += st.top();
                st.pop();
            }
            st.pop(); // Remove the opening parenthesis
        }
        // If the character is an operator
        else if (isOperator(ch)) {
            // Pop operators from the stack with greater or equal precedence
            while (!st.empty() && precedence(st.top()) > precedence(ch)) {
                prefix += st.top();
                st.pop();
            }
            st.push(ch); // Push the current operator to the stack
        }
    }

    // Pop any remaining operators from the stack
    while (!st.empty()) {
        prefix += st.top();
        st.pop();
    }

    // Reverse the prefix expression to get the final prefix result
    prefix = reverseString(prefix);

    return prefix;
}

int main() {
    // Input infix expression from the user
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    // Convert infix to prefix and display the result
    string prefix = infixToPrefix(infix);
    cout << "The prefix expression is: " << prefix << endl;

    return 0;
}
