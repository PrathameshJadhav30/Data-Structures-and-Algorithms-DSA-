#include <iostream>
#include <queue>
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
    // Function to perform Level Order Traversal Line by Line
    void printLevelOrderLineByLine(TreeNode* root) {
        if (root == nullptr)
            return;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size(); // Number of nodes at current level

            // Process all nodes at current level
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* current = q.front();
                q.pop();

                cout << current->val << " ";

                // Enqueue left child if exists
                if (current->left)
                    q.push(current->left);

                // Enqueue right child if exists
                if (current->right)
                    q.push(current->right);
            }
            // Print newline after each level
            cout << endl;
        }
    }
};

// Driver code
int main() {
    // Creating the following binary tree:
    //         1
    //       /   \
    //      2     3
    //     / \     \
    //    4   5     6

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution sol;
    cout << "Level Order Traversal Line by Line:" << endl;
    sol.printLevelOrderLineByLine(root);

    return 0;
}
