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
    bool ans = true;
    void solve( TreeNode *   root, long long low, long long high)
    {
        if( root ==NULL)return ;
        if(root -> val <= low || root -> val >= high)
           ans= false;
        solve( root->left, low, root->val);
        
        
        solve( root->right, root->val ,high);
        
        
    }
public:
    bool isValidBST(TreeNode* root) {
        long long low=-1e18;
        long long high =1e18;
        solve( root, low, high);
        return ans;
    }
};