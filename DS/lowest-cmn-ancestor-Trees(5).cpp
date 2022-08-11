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
--->Brute force approach 
Find the path from root to both the nodes, store them and find the last common value in the path array. 
But, the Time complexity : O(2n) and Space complexity : O(2n) 
--->Optimized approach
Follow the BFS traversal - recursive traversal
class Solution {
public:
    //-----Time comp = O(n) SC: O(n) [WC like skwewed trees]--------
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
     //if the root is itself either of the two nodes then the root becomes the LCA of both
        if(!root || root==p || root==q) return root;
    //we perform the recursiv traversal ie) the left-root-right 
  
       TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
          //so if we find a node on either left/right we return the found node
    //if not found we return null
    //if we found on right we return the right node as left is null & vice versa
        if(!left) return right;
        if(!right) return left;
    //if we found one node on right and other on left then we return both and their lca their respective root is returned 
        return root;
    }
};
