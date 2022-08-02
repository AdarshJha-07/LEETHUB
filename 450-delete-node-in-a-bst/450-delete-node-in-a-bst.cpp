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
    
    TreeNode *getRightMost(TreeNode *root){
        
        if(root == NULL){
            return NULL;
        }
        
        
        while(root->right != NULL){
            root = root->right;
        }
        
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
    
        if(root == NULL){
            return NULL;
        }
        
        if(root->val > key){
            root->left = deleteNode(root->left,key);
        }
        else if(root->val < key){
            root->right = deleteNode(root->right,key);
        }
        else{
            
            if(root->left == NULL and root->right == NULL){
                return NULL;
            }
            else if(root->left == NULL){
                return root->right;
            }
            else if(root->right == NULL){
                return root->left;
            }
            else{
                
                TreeNode *x = getRightMost(root->left);
                
                root->val = x->val;
                
                root->left = deleteNode(root->left,x->val);
            }
        }
        
        
        return root;
    }
};