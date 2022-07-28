/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    unordered_map<TreeNode*,int>mp;
    int solve(TreeNode* root){
             if(root==NULL)return 0;
        
        if(mp.find(root)!=mp.end())return mp[root];
        int g1=0,g2=0,g3=0,g4=0;
       if(root->left!=NULL&&root->left->left!=NULL)g1=solve(root->left->left);
       if(root->left!=NULL&&root->left->right!=NULL)g2=solve(root->left->right);
       if(root->right!=NULL&&root->right->left!=NULL)g3=solve(root->right->left);
        
       if(root->right!=NULL&&root->right->right!=NULL)g4=solve(root->right->right);
        int c1=g1+g2+g3+g4+root->val;
        
        
        int c2=0,l1=0,l2=0;
        if(root->left!=NULL)l1=solve(root->left);
        if(root->right!=NULL)l2=solve(root->right);
        c2=l1+l2;
        
     return mp[root]=max(c1,c2);
    }
    
    
public:
    int rob(TreeNode* root) {
        
      
   return  solve(root);
    }
};