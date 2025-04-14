#include <iostream>
#include <climits> // For INT_MIN
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Recursive function to find maximum in binary tree
int findMax(Node* root) {
    if (root == nullptr)
        return INT_MIN;

    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);

    return max(root->data, max(leftMax, rightMax));
}

int main() {
    // Create a sample binary tree:
    //        10
    //       /  \
    //      20   30
    //     / \
    //    40 50

    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);

    cout << "Maximum value in the binary tree is: " << findMax(root) << endl;

    return 0;
}
