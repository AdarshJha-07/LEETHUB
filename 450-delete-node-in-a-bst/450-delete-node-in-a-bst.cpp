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
    TreeNode* del(TreeNode *root,int k){
        if(root==NULL) return NULL ;
         
        if(root->val>k)
       root->left= del(root->left,k);
       else if(root->val<k)
         root->right=  del(root->right,k);
        else{
            
            if(root->right==NULL){
               // delete root;
            return root->left;}
            else if(root->left==NULL){
                return root->right;
            }
            else{
                TreeNode *curr=root->right;
                while(curr->left!=NULL)
                {
                    curr=curr->left;
                }
                root->val=curr->val;
               root->right=del(root->right, curr->val );
        
                }
        }
    return root;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
    
     return   del(root,key);    
      //  return root;
    }
};