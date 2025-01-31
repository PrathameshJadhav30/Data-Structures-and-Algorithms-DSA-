#include <iostream>
using namespace std;

// Definition of a Binary Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Inorder Traversal (Left -> Root -> Right)
void inorderTraversal(Node* root) {
    if (root == nullptr)
        return;

    inorderTraversal(root->left);   // Visit left subtree
    cout << root->data << " ";      // Visit root
    inorderTraversal(root->right);  // Visit right subtree
}

int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    
    return 0;
}
