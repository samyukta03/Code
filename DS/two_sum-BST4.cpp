Given the root of a Binary Search Tree and a target number k,
 return true if there exist two elements in the BST such that their sum is equal to the given target.
   //sc & tc = O(n) : this is a inorder approach
   /* inorder traversal of bst results in a sorted array 
   and hence we can traverse through the sorted from either ends and find the two numbers */
class Solution {
public:
   
    void inorder(TreeNode* root,vector<int>& ans){
        if(!root) return;
        if(root){
            inorder(root->left,ans);
            ans.push_back(root->val);
            inorder(root->right,ans);
        }
    }
    bool findTarget(TreeNode* root, int k) {
      
        if(!root) return false;
    vector<int>ans; //array to store inorder traversal
        inorder(root,ans);
        int i=0,j=ans.size()-1; //declare two ptrs i to 0th and j to nth 
        while(i < j){
        if(ans[i]+ans[j]==k) return true; //if the sum of i and jth element = target returh true
        else if(ans[i]+ans[j] > k) j--; //if the value if larger means u've decrease j as the max val node is larger
        else i++; //else just move forward from start 
        }
     return false;
    }
  
};