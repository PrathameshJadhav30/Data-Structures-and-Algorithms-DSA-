#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int& postIndex, unordered_map<int, int>& inorderMap) {
    if (inStart > inEnd) return nullptr;

    int rootVal = postorder[postIndex--];
    TreeNode* root = new TreeNode(rootVal);

    if (inStart == inEnd) return root;

    int inIndex = inorderMap[rootVal];

    root->right = buildTreeHelper(inorder, postorder, inIndex + 1, inEnd, postIndex, inorderMap);
    root->left = buildTreeHelper(inorder, postorder, inStart, inIndex - 1, postIndex, inorderMap);

    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int, int> inorderMap;
    int n = inorder.size();
    for (int i = 0; i < n; ++i)
        inorderMap[inorder[i]] = i;

    int postIndex = n - 1;
    return buildTreeHelper(inorder, postorder, 0, n - 1, postIndex, inorderMap);
}

void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    TreeNode* root = buildTree(inorder, postorder);

    cout << "Inorder of constructed tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}
