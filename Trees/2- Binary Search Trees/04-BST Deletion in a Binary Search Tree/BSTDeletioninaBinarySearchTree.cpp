#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Function to find the minimum value in the right subtree
Node* findMin(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the BST
Node* deleteNode(Node* root, int key) {
    if (root == nullptr) {
        return root;  // Base case: tree is empty
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);  // Recur for left subtree
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);  // Recur for right subtree
    } else {
        // Node to be deleted found
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor (minimum value in the right subtree)
        Node* temp = findMin(root->right);
        root->data = temp->data;  // Copy inorder successor's value to this node
        root->right = deleteNode(root->right, temp->data);  // Delete the inorder successor
    }
    return root;
}

// Function to insert a node in the BST
Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to perform an inorder traversal
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Inorder traversal before deletion: ";
    inorder(root);
    cout << endl;

    root = deleteNode(root, 50);

    cout << "Inorder traversal after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
