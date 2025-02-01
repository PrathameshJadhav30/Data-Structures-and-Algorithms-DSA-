#include <iostream>
using namespace std;

// Definition of a Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Postorder Traversal: Left -> Right -> Root
void postorderTraversal(Node* root) {
    if (root == nullptr)
        return;
    
    // Recursive call on left subtree
    postorderTraversal(root->left);
    
    // Recursive call on right subtree
    postorderTraversal(root->right);
    
    // Visit the node
    cout << root->data << " ";
}

int main() {
    // Creating a simple binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << endl;
    
    return 0;
}
