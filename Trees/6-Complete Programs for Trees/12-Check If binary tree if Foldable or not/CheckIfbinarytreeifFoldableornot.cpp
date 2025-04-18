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

// Function to check if two trees are mirror structures
bool isMirrorStructure(Node* n1, Node* n2) {
    if (!n1 && !n2)
        return true;
    if (!n1 || !n2)
        return false;
    return isMirrorStructure(n1->left, n2->right) &&
           isMirrorStructure(n1->right, n2->left);
}

// Function to check if tree is foldable
bool isFoldable(Node* root) {
    if (!root)
        return true;
    return isMirrorStructure(root->left, root->right);
}

// Example usage
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);

    if (isFoldable(root))
        cout << "Tree is Foldable" << endl;
    else
        cout << "Tree is Not Foldable" << endl;

    return 0;
}
