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

// Preorder Traversal (Root -> Left -> Right)
void preorderTraversal(Node* root) {
    if (root == nullptr)
        return;

    cout << root->data << " ";      // Visit root
    preorderTraversal(root->left);  // Visit left subtree
    preorderTraversal(root->right); // Visit right subtree
}

int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    
    return 0;
}
