/*According to the definition of LCA on Wikipedia: The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself)*/

1. Lowest common ancestor - Binary search tree
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.
class Solution {
public:
    //Tc: O(h) and SC:O(1)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
 //since this is a bst you can check if both the nodes are in left or right or in either.
 //if both have val lesser than root then check the left side of tree to find their splitting point   
     if(p->val < root->val&&q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
 //if both have val greater than root then check the right side of tree to find their splitting point 
     if(p->val > root->val&&q->val > root->val)   
              return lowestCommonAncestor(root->right, p, q);
//if one is greater and other is lesser than root or vice versa then the current root is the only common point so return that 
     if(p->val > root->val && q->val < root->val || p->val < root->val && q->val > root->val ) return root;
        return root;
};

2. Lowest Common ancestor - Binary tree
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
