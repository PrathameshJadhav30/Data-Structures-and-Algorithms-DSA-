#include <iostream>
using namespace std;

// Definition of the Tree Node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Preorder Traversal (Root → Left → Right)
void preorder(TreeNode* root) {
    if (root == NULL) return;
    cout << root->val << " ";  // Visit root
    preorder(root->left);      // Traverse left subtree
    preorder(root->right);     // Traverse right subtree
}

// Inorder Traversal (Left → Root → Right)
void inorder(TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);       // Traverse left subtree
    cout << root->val << " ";  // Visit root
    inorder(root->right);      // Traverse right subtree
}

// Postorder Traversal (Left → Right → Root)
void postorder(TreeNode* root) {
    if (root == NULL) return;
    postorder(root->left);     // Traverse left subtree
    postorder(root->right);    // Traverse right subtree
    cout << root->val << " ";  // Visit root
}

int main() {
    // Sample Tree:
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

    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}
