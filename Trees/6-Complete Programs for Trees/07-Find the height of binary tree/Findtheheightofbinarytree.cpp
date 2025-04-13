#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    // Constructor
    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

class Solution {
public:
    // Function to find the height of a binary tree
    int height(TreeNode* root) {
        // Base case: empty tree has height -1 (if height is in terms of edges)
        // Use 0 if you define height in terms of number of nodes
        if (root == nullptr) {
            return -1; // return 0 if counting nodes instead of edges
        }

        // Recursively find the height of left and right subtrees
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        // Height of tree = max height of left/right subtree + 1
        return max(leftHeight, rightHeight) + 1;
    }
};
int main() {
    /*
        Sample tree:
              1
             / \
            2   3
           /
          4
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    Solution sol;
    cout << "Height of the tree: " << sol.height(root) << endl;  // Output: 2
    return 0;
}
