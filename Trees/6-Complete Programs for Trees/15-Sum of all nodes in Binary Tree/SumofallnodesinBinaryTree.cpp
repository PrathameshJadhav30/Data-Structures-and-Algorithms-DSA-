#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    // Constructors
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Function to calculate sum of all nodes
    int sumOfNodes(TreeNode* root) {
        // Base case: if root is null, return 0
        if (root == nullptr) {
            return 0;
        }

        // Recursive call: sum of current node + left subtree + right subtree
        int leftSum = sumOfNodes(root->left);
        int rightSum = sumOfNodes(root->right);

        return root->val + leftSum + rightSum;
    }
};

// Helper function to create a simple tree (for testing)
TreeNode* createSampleTree() {
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node2 = new TreeNode(2, node1, node3);

    TreeNode* node6 = new TreeNode(6);
    TreeNode* node9 = new TreeNode(9);
    TreeNode* node7 = new TreeNode(7, node6, node9);

    TreeNode* root = new TreeNode(4, node2, node7);

    return root;
}

int main() {
    Solution sol;
    TreeNode* root = createSampleTree(); // Creates tree: [4,2,7,1,3,6,9]
    int sum = sol.sumOfNodes(root);
    cout << "Sum of all nodes in the binary tree: " << sum << endl;
    return 0;
}
