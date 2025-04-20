#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Function to check the Children Sum Property
    bool checkChildrenSum(TreeNode* root) {
        // Base Case: Empty node or leaf node
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            return true;
        }

        // Get left and right children's values
        int leftVal = (root->left != nullptr) ? root->left->val : 0;
        int rightVal = (root->right != nullptr) ? root->right->val : 0;

        // Check the current node and recursively check left and right subtrees
        if (root->val == leftVal + rightVal &&
            checkChildrenSum(root->left) &&
            checkChildrenSum(root->right)) {
            return true;
        }

        return false;
    }
};

// Sample usage
int main() {
    /*
           10
          /  \
         8    2
        / \    \
       3   5    2
    */

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(8);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(2);

    Solution sol;
    if (sol.checkChildrenSum(root)) {
        cout << "The tree follows the Children Sum Property." << endl;
    } else {
        cout << "The tree does NOT follow the Children Sum Property." << endl;
    }

    // Free memory (optional for small test cases)
    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
