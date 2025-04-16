#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to print spiral (zigzag) level order traversal
vector<int> spiralOrderTraversal(TreeNode* root) {
    vector<int> result;

    if (root == nullptr) return result;

    // Two stacks to store alternate levels
    stack<TreeNode*> s1; // For levels to be printed left-to-right
    stack<TreeNode*> s2; // For levels to be printed right-to-left

    // Push the root to the first stack
    s1.push(root);

    while (!s1.empty() || !s2.empty()) {
        // Process current level from s1 (left-to-right)
        while (!s1.empty()) {
            TreeNode* curr = s1.top();
            s1.pop();
            result.push_back(curr->val);

            // Left to right: first left then right child
            if (curr->left) s2.push(curr->left);
            if (curr->right) s2.push(curr->right);
        }

        // Process next level from s2 (right-to-left)
        while (!s2.empty()) {
            TreeNode* curr = s2.top();
            s2.pop();
            result.push_back(curr->val);

            // Right to left: first right then left child
            if (curr->right) s1.push(curr->right);
            if (curr->left) s1.push(curr->left);
        }
    }

    return result;
}
int main() {
    // Create tree: 
    //        1
    //      /   \
    //     2     3
    //    / \   / \
    //   4   5 6   7

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> spiral = spiralOrderTraversal(root);

    cout << "Spiral Order Traversal: ";
    for (int val : spiral) {
        cout << val << " ";
    }

    return 0;
}
