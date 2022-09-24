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
    vector<vector<int>>ans;
    void solve( TreeNode * root ,vector<int>&temp ,int target){
        
        if( root == NULL) return;
        
        if(root -> left == NULL && root -> right == NULL) {
            if(target == 0) ans.push_back(temp);
            return ;
        }
        if(root->left)
        {
            temp.push_back(root->left->val);
            solve( root -> left , temp, target - root->left->val);
            temp.pop_back();
        }
        if(root->right)
        {
        temp.push_back(root->right->val);
        solve( root -> right , temp, target - root->right->val);
        temp.pop_back();
        }
        
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return ans;
        vector<int>temp;
        temp.push_back(root->val);
        solve(root, temp , targetSum - root->val);
        return ans;
        
    }
};
