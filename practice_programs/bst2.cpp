#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int val) : key(val), left(NULL), right(NULL) {}
};

// Utility function to reverse inorder traversal the tree and accumulate the sum
void modifyBSTUtil(Node* node, int& sum) {
    if (!node) return;

    // Traverse the right subtree first (reverse inorder)
    modifyBSTUtil(node->right, sum);

    // Accumulate sum
    sum += node->key; 
    // Update the current node
    if (node->key < sum &&  node->left != NULL)
        node->key += sum;
    else
        node->key = sum;

    // Traverse the left subtree
    modifyBSTUtil(node->left, sum);
}

// Function to modify the BST
void modifyBST(Node* root) {
    int sum = 0;
    modifyBSTUtil(root, sum);
}

// Helper function to perform inorder traversal of the BST
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    std::cout << " " << root->key;
    inorder(root->right);
}

// Main method to test the modifyBST function
int main() {
    Node* root = new Node(5);
    root->left = new Node(5);
    root->right = new Node(6);
    root->right->left = new Node(5);

    std::cout << "Inorder traversal before modification:";
    inorder(root);
    std::cout << std::endl;

    modifyBST(root);

    std::cout << "Inorder traversal after modification:";
    inorder(root);
    std::cout << std::endl;

    return 0;
}
