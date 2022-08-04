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
    bool ans=true;
    int mxl=INT_MIN;
    int flag=0;
    int solve(TreeNode* root ){
        if(!root)return 0;
        
        int l=solve(root->left);
        
        int r=solve(root->right);
        
        return max(l,r)+1;
    }
public:
    bool isCompleteTree(TreeNode* root) {
        
        bool ans=true;
        int flag=0;
        queue<TreeNode*>q;
        q.push(root);
      //  q.push(NULL);
        while(!q.empty()){
            TreeNode * node=q.front();
            q.pop();
            // if(node==NULL){
            //     if(!q.empty())q.push(NULL);
            //     continue;
            // }
            if(flag==1&&(node->left!=NULL||node->right!=NULL))ans=false;
            
            if(node->left!= NULL&&flag==0){
                q.push(node->left);
            }
            else if(flag==0&&node->left==NULL)flag=1;
            
            if(flag==0&&node->right!=NULL){
                 q.push(node->right);
            }
            else if(flag==0&&node->right==NULL)flag=1;
               
         if(flag&&node->right!=NULL)ans=false;
        
            
            
        }
        return ans;
    }
};