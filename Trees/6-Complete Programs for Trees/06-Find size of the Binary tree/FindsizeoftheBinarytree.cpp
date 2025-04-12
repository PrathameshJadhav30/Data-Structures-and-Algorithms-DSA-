#include <iostream>
using namespace std;

// Definition for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
public:
    // Function to find the size of the binary tree
    int size(Node* root) {
        if (root == nullptr) {
            return 0; // Base case: empty tree has size 0
        }

        // Recursively calculate size of left and right subtrees
        int leftSize = size(root->left);
        int rightSize = size(root->right);

        // Total size = 1 (current node) + leftSize + rightSize
        return 1 + leftSize + rightSize;
    }
};
int main() {
    // Creating a simple binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    cout << "Size of the binary tree: " << sol.size(root) << endl;

    return 0;
}
