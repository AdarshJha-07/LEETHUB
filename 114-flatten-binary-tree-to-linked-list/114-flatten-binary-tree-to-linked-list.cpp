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
public:
  
    
    void flatten(TreeNode* root) {
       
       TreeNode * curr=root;
     while(curr){
         
         if(curr->left!=NULL){
             
             TreeNode * predecessor=curr->left;
             while(predecessor->right){
                 predecessor=predecessor->right;
                 
             }
             if(predecessor->right==NULL){
                 predecessor->right=curr->right;
             }
             curr->right=curr->left;
             curr->left=NULL;
         }
         else{
             
             curr=curr->right;
            
            
         }
         
         
         
     }
    }
};