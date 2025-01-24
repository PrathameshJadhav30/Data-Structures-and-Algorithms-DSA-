#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to convert postfix to prefix
string postfixToPrefix(const string& postfix) {
    stack<string> s;

    // Traverse the postfix expression using a normal for loop
    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];

        // If the character is an operand, push it onto the stack
        if (isalnum(c)) {
            s.push(string(1, c));
        } 
        // If the character is an operator
        else if (isOperator(c)) {
            // Pop two operands from the stack
            string op2 = s.top(); s.pop();
            string op1 = s.top(); s.pop();

            // Form the prefix expression
            string prefix = c + op1 + op2;

            // Push the result back onto the stack
            s.push(prefix);
        }
    }

    // The remaining element in the stack is the final prefix expression
    return s.top();
}

int main() {
    string postfix;
    cout << "Enter a postfix expression: ";
    cin >> postfix;

    string prefix = postfixToPrefix(postfix);

    cout << "The prefix expression is: " << prefix << endl;

    return 0;
}
