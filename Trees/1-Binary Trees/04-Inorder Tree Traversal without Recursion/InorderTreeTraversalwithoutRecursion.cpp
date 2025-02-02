#include <iostream>
#include <stack>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

void inorderTraversal(Node* root) {
    stack<Node*> s;
    Node* current = root;

    while (current != nullptr || !s.empty()) {
        // Reach the leftmost node of the current node
        while (current != nullptr) {
            s.push(current);
            current = current->left;
        }

        // Process the top node
        current = s.top();
        s.pop();
        cout << current->data << " ";

        // Move to the right subtree
        current = current->right;
    }
}

// Helper function to create a sample tree
Node* createSampleTree() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    return root;
}

int main() {
    Node* root = createSampleTree();
    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    return 0;
}
