Given the root of a binary tree, invert the tree, and return its root.

class Solution {
public:
TreeNode* invert(TreeNode* root){
    if(!root) return NULL;
    invert(root->left);
    invert(root->right);
    swap(root->left,root->right);
 return root;
}
}
tc = O(n) n-no of nodes in tree
sc = O(h) h-height of tree
