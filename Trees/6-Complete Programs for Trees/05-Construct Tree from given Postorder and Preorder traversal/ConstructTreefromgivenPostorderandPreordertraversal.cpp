#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

Node* constructTreeUtil(int pre[], int post[], int& preIndex, int l, int h, int size) {
    if (preIndex >= size || l > h) return nullptr;

    Node* root = new Node(pre[preIndex++]);

    // If there's only one node or we reached the end
    if (l == h || preIndex >= size)
        return root;

    // Find the index of next element in post[]
    int i;
    for (i = l; i <= h; i++) {
        if (post[i] == pre[preIndex])
            break;
    }

    // Build left and right subtrees
    if (i <= h) {
        root->left = constructTreeUtil(pre, post, preIndex, l, i, size);
        root->right = constructTreeUtil(pre, post, preIndex, i + 1, h - 1, size);
    }

    return root;
}

Node* constructTree(int pre[], int post[], int size) {
    int preIndex = 0;
    return constructTreeUtil(pre, post, preIndex, 0, size - 1, size);
}

void printInorder(Node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

// Example usage
int main() {
    int pre[] = {1, 2, 4, 5, 3, 6, 7};
    int post[] = {4, 5, 2, 6, 7, 3, 1};
    int size = sizeof(pre) / sizeof(pre[0]);

    Node* root = constructTree(pre, post, size);

    cout << "Inorder traversal of constructed tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}
