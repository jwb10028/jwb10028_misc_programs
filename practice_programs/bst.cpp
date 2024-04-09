// C++ program to insert a node
// in a BST
#include <bits/stdc++.h>
using namespace std;
 
// Given Node
struct node
{
    int key;
    struct node *left, *right;
};
 
// Function to create a new BST node
struct node* newNode(int item)
{
    struct node* temp = (struct node*)malloc(
                  sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
// Function to insert a new node with
// given key in BST
struct node* insert(struct node* node, int key)
{
     
    // If the tree is empty, return a new node
    if (node == NULL)
        return newNode(key);
 
    // Otherwise, recur down the tree
    if (key <= node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
 
    // Return the node pointer
    return node;
}
 
// Function to do inorder traversal of BST
void inorder(struct node* root)
{
    if (root != NULL) 
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// Function to modify the BST
void modifyBSTUtil(struct node* node, int& sum) {
    // Base case
    if (node == nullptr) {
        return;
    }

    // Recur for the right subtree first
    modifyBSTUtil(node->right, sum);

    // Update the sum with the current node's key
    sum = sum + node->key;

    // Change the node's key to the sum
    node->key = sum;

    // Recur for the left subtree
    modifyBSTUtil(node->left, sum);
}

void modifyBST(struct node* root) {
    int sum = 0;
    modifyBSTUtil(root, sum);
}
 
// Driver Code
int main()
{
     
    /* Let us create following BST 
              50 
           /     \ 
          30      70 
         /  \    /  \ 
       20   40  60   80 
   */
    struct node* root = NULL;
 
    // Inserting value 50
    root = insert(root, 5);
 
    // Inserting value 30
    insert(root, 6);
 
    // Inserting value 20
    insert(root, 5);
 
    // Print the BST
    inorder(root);

    modifyBST(root);
    cout << "\n";
    inorder(root);
 
    return 0;
}
 
// This code is contributed by shubhamsingh10