#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Recursive function to find LCA of two nodes
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: if current node is null or equal to p or q
        if (root == nullptr || root == p || root == q) {
            return root;
        }

        // Search in left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If both sides are non-null, current node is the LCA
        if (left != nullptr && right != nullptr) {
            return root;
        }

        // Otherwise, return the non-null side
        return (left != nullptr) ? left : right;
    }
};

// Helper function to create a simple binary tree for demonstration
TreeNode* buildSampleTree(TreeNode*& p, TreeNode*& q) {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    // Setting p = node with value 5, q = node with value 1
    p = root->left;       // Node with value 5
    q = root->right;      // Node with value 1

    return root;
}

int main() {
    TreeNode* p;
    TreeNode* q;
    TreeNode* root = buildSampleTree(p, q);

    Solution sol;
    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);

    cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is: " << lca->val << endl;

    return 0;
}
