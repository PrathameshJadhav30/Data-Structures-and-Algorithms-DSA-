#include <iostream>
#include <queue>

using namespace std;

// Definition of a Tree Node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

// Function to insert a node in Level Order
void insert(TreeNode* root, int key) {
    if (root == nullptr) { 
        root = new TreeNode(key);  // If tree is empty, create root
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    // Perform level order traversal to find an empty spot
    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();

        // Check left child
        if (temp->left == nullptr) {
            temp->left = new TreeNode(key);
            return;
        } else {
            q.push(temp->left);
        }

        // Check right child
        if (temp->right == nullptr) {
            temp->right = new TreeNode(key);
            return;
        } else {
            q.push(temp->right);
        }
    }
}

// Function to print level-order traversal of the tree
void printLevelOrder(TreeNode* root) {
    if (root == nullptr) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        
        cout << temp->val << " "; // Print node value

        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
}

// Driver code
int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(40);
    root->left->right = new TreeNode(50);

    cout << "Before Insertion: ";
    printLevelOrder(root);
    cout << endl;

    insert(root, 60);  // Insert a new node

    cout << "After Insertion: ";
    printLevelOrder(root);
    cout << endl;

    return 0;
}
