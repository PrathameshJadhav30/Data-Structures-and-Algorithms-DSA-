#include <iostream>
#include <unordered_map>
#include <vector>  // ✅ Include this for vector usage
using namespace std;

// Define the structure for a tree node
struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Index to track current root in preorder
    int preorderIndex = 0;

    // Map to store value -> index mappings from inorder array
    unordered_map<char, int> inorderMap;

    // Recursive function to build tree
    TreeNode* buildTreeHelper(vector<char>& preorder, vector<char>& inorder, int inStart, int inEnd) {
        if (inStart > inEnd) return NULL;

        // Get current root from preorder
        char rootVal = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootVal);

        // Find root in inorder to split into left and right
        int rootIndex = inorderMap[rootVal];

        // Build left and right subtrees recursively
        root->left = buildTreeHelper(preorder, inorder, inStart, rootIndex - 1);
        root->right = buildTreeHelper(preorder, inorder, rootIndex + 1, inEnd);

        return root;
    }

    // Main function to start tree construction
    TreeNode* buildTree(vector<char>& preorder, vector<char>& inorder) {
        // Fill map with inorder value -> index
        for (int i = 0; i < inorder.size(); ++i) {
            inorderMap[inorder[i]] = i;
        }
        return buildTreeHelper(preorder, inorder, 0, inorder.size() - 1);
    }

    // Utility function to print postorder (for testing)
    void printPostorder(TreeNode* root) {
        if (!root) return;
        printPostorder(root->left);
        printPostorder(root->right);
        cout << root->val << " ";
    }
};

int main() {
    Solution sol;
    vector<char> preorder = {'A', 'B', 'D', 'E', 'C', 'F'};
    vector<char> inorder = {'D', 'B', 'E', 'A', 'F', 'C'};

    TreeNode* root = sol.buildTree(preorder, inorder);

    cout << "Postorder traversal of constructed tree: ";
    sol.printPostorder(root);  // Expected: D E B F C A
    cout << endl;

    return 0;
}
