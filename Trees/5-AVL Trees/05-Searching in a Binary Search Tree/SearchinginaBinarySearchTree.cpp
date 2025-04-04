#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

TreeNode* searchBST(TreeNode* root, int key) {
    if (root == NULL || root->val == key)
        return root;
    
    if (key < root->val)
        return searchBST(root->left, key);
    else
        return searchBST(root->right, key);
}

// Helper function to insert a node in BST
TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL)
        return new TreeNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    
    return root;
}

int main() {
    TreeNode* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    int key = 60;
    TreeNode* result = searchBST(root, key);

    if (result != NULL)
        cout << "Found node with value: " << result->val << endl;
    else
        cout << "Value " << key << " not found in BST." << endl;

    return 0;
}
