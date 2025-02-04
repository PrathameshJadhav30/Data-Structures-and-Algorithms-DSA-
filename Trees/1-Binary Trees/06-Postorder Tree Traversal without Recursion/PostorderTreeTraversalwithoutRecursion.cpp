#include <iostream>
#include <stack>
using namespace std;

// Definition of the Tree Node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to perform postorder traversal without recursion
void postorderTraversal(TreeNode* root) {
    if (root == NULL)
        return;

    stack<TreeNode*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        TreeNode* node = s1.top();
        s1.pop();
        s2.push(node);

        if (node->left)
            s1.push(node->left);
        if (node->right)
            s1.push(node->right);
    }

    // Print the nodes in postorder
    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

int main() {
    // Creating a sample binary tree:
    //         1
    //        / \
    //       2   3
    //      / \  / \
    //     4  5 6   7
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Postorder Traversal (without recursion): ";
    postorderTraversal(root);

    return 0;
}
