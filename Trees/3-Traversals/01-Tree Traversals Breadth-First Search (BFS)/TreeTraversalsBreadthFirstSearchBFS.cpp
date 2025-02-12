#include <iostream>
#include <queue>  // For using queue
using namespace std;

// Definition of a tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to perform BFS (Level Order Traversal)
void bfsTraversal(TreeNode* root) {
    if (root == NULL) {
        cout << "Tree is empty." << endl;
        return;
    }

    queue<TreeNode*> q;  // Queue for BFS
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        cout << current->val << " ";  // Process the current node

        // Push left child to the queue if it exists
        if (current->left != NULL) {
            q.push(current->left);
        }

        // Push right child to the queue if it exists
        if (current->right != NULL) {
            q.push(current->right);
        }
    }
    cout << endl;
}

// Driver code
int main() {
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Breadth-First Search (BFS) / Level Order Traversal: ";
    bfsTraversal(root);

    return 0;
}
