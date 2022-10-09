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
    stack<TreeNode *>st1;
     stack<TreeNode *>st2;
    
    int next()
    {
        TreeNode *curr=st1.top();
        st1.pop();
        pushlAll(curr->right);
        return curr->val;
    }
    void pushlAll(TreeNode *root)
    {
        for(;root!=NULL;st1.push(root),root=root->left);
    }
    int before(){
        TreeNode *curr=st2.top();
        st2.pop();
        pushrAll(curr->left);
        return curr->val;
    }
    void pushrAll(TreeNode *root){
        for(;root!=NULL;st2.push(root),root=root->right);
    }
    
    
public:
    bool findTarget(TreeNode* root, int k) {
     pushlAll(root);
     pushrAll(root);
        int i=next();
        int j=before();
     while(!st1.empty()&&!st2.empty()&&i<j){
        // cout<<i<<" "<<j<<endl;
          if(i+j==k)return true;
         else if(i+j<k){
             i=next();
         }
         else{
             j=before();
         }
     }
        return false;
    }
};