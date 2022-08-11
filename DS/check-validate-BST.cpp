 /*Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.*/
 
 void inorder(TreeNode* root,vector<int>& ans){
        if(!root) return;
        if(root){
            inorder(root->left,ans);
            ans.push_back(root->val);
            inorder(root->right,ans);
        }
    }
    bool isValidBST(TreeNode* root) {
        if(!root) return false; 
       // bool flag=true;
        vector<int>ans;
        inorder(root,ans);
        for(int i=0;i<ans.size()-1;i++){
            if(ans[i]>=ans[i+1]) { return false;}
        }
        return true;
    }
    //time comp O(n)
    //space comp O(n)