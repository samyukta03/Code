/* 
1. Lowest common ancestor - Binary search tree
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself)
*/
class Solution {
public:
    //Tc: O(h) and SC:O(1)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
    
     if(p->val < root->val&&q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);

     if(p->val > root->val&&q->val > root->val)   
              return lowestCommonAncestor(root->right, p, q);

     if(p->val > root->val && q->val < root->val || p->val < root->val && q->val > root->val ) return root;
        return root;
};

/*
2. Lowest Common ancestor - Binary tree

*/