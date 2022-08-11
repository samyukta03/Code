Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path 
such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.

class Solution{
    public:
    bool pathsum(TreeNode*root, int targetSum){
        if(!root) return false; //default condition check
        int sum_so_far=0;
        sum_so_far+=root->val;
         //check if the sum u've got till now is equal to the target
        if(sum_so_far==targetSum && !root->left && !root->right) return true; 
       //now for the remaning val ie) target - sum so far check for nodes in right and left of tree
        bool leftval = pathsum(root->left,targetSum-sum_so_far); 
        bool rightval = pathsum(root->right,targetSum-sum_so_far); 
        // return which ever side has the result
   return leftval || rightval;
    }
}

the time complexity is O(n) n=no of nodes in the tree
Space complexity = O(h) h is the depth of tree