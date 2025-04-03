#include <iostream>
using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to insert a node into the binary tree (for testing)
Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }
    if (key < root->data) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    return root;
}

// Function to search for a value in the Binary Tree
bool search(Node* root, int key) {
    if (root == nullptr) return false;
    if (root->data == key) return true;
    return search(root->left, key) || search(root->right, key);
}

int main() {
    Node* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 2);
    root = insert(root, 7);
    
    int key = 7;
    if (search(root, key)) {
        cout << "Key " << key << " found in the binary tree!" << endl;
    } else {
        cout << "Key " << key << " not found in the binary tree!" << endl;
    }
    
    return 0;
}
