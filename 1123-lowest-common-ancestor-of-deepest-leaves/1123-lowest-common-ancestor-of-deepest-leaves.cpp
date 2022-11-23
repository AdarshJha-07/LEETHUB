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
       int ans;
    void height(TreeNode* root , int op){
        if(root == NULL) return;
        if(op > ans){
            ans = op;
        }
        height(root->left, op+1);
        height(root->right,op+1);
    }
    TreeNode* solve(TreeNode* root,int op){
        if(root == NULL) return NULL;
        
        if(op==ans) return root;
        TreeNode* left = solve(root->left,op+1);
        TreeNode* right = solve(root->right,op+1);
         
      if(left && right) return root;
     
     return left == NULL?right : left;   
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
          ans = INT_MIN;
       height(root,0);
      return solve(root,0);
    }
};