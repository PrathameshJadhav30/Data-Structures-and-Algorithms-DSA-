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

/**
 * Solution class containing the function to check if two trees are identical.
 */
class Solution {
public:
    bool isIdentical(TreeNode* p, TreeNode* q) {
        // Both nodes are null => identical at this node
        if (!p && !q) return true;

        // One node is null and the other is not => not identical
        if (!p || !q) return false;

        // Values of current nodes don't match
        if (p->val != q->val) return false;

        // Recursively check left and right subtrees
        return isIdentical(p->left, q->left) && isIdentical(p->right, q->right);
    }
};

/**
 * Sample binary tree builder and test.
 */
int main() {
    // Tree 1
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);

    // Tree 2 (identical to Tree 1)
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);

    Solution sol;
    if (sol.isIdentical(root1, root2)) {
        cout << "The two trees are identical." << endl;
    } else {
        cout << "The two trees are NOT identical." << endl;
    }

    return 0;
}
