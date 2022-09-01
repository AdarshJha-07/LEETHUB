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
    int count =0;
    void solve(TreeNode*root,int max)
    {
        
        if(root==NULL)return ;
        if(max<=root->val)
        {
            count++;
         max=root->val;
        
        }
        solve(root->left,max);
        
         solve(root->right,max);
        
    }
    
    
public:
    int goodNodes(TreeNode* root) {
        int h=INT_MIN;
        solve(root,h);
        return count;
        
    }
};