#include <iostream>
#include <queue>
using namespace std;

// Definition of a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

// Function to perform Level Order Traversal
void levelOrderTraversal(TreeNode* root) {
    if (root == nullptr)
        return;

    // Use a queue to store nodes level by level
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        // Print the current node
        cout << current->val << " ";

        // Push left and right children to the queue
        if (current->left != nullptr)
            q.push(current->left);
        if (current->right != nullptr)
            q.push(current->right);
    }
}
int main() {
    // Creating the tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    cout << "Level Order Traversal: ";
    levelOrderTraversal(root); // Output: 1 2 3 4 5 6

    return 0;
}
