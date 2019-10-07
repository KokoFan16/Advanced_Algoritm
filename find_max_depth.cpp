#include<iostream>
#include <algorithm>

// Define a binary search tree node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

// Find max Depth in BST
int maxDepth(TreeNode* root)
{
    if(root == NULL)
        return 0;
    
    return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

int main()
{
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);
    
    int depth = maxDepth(root);
    
    std::cout << depth << std::endl;
}
