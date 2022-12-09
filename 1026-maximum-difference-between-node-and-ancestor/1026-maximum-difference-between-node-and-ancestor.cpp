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
    unordered_map<int,int>ump,ump2;
     unordered_map<int,int>ump3,ump4;
    
     void solve(TreeNode *root,int maxi){
        if(root == NULL) return ;
         
         ump[root->val] = max(maxi,root->val);
         
         solve(root->left,ump[root->val]);
         solve(root->right,ump[root->val]);
        
        return ;
    }
    void solve2(TreeNode *root,int mini){
        if(root == NULL) return;
        
         solve2(root->left,mini);
         solve2(root->right,mini);
           
         ump2[root->val] = min(mini,root->val);
        return;
    }
    void solve3(TreeNode *root,int mini){
        if(root == NULL) return ;
         
         ump3[root->val] = min(mini,root->val);
         
         solve3(root->left,ump3[root->val]);
         solve3(root->right,ump3[root->val]);
        
        return ;
    }
     void solve4(TreeNode *root,int maxi){
         if(root == NULL) return;
        
         solve4(root->left,maxi);
         solve4(root->right,maxi);
           
         ump4[root->val] = max(maxi,root->val);
        return;
    }
public:
    int maxAncestorDiff(TreeNode* root) {
         solve(root,INT_MIN);
         solve2(root,INT_MAX);
        solve3(root,INT_MAX);
        solve4(root,INT_MIN);
        int ans = INT_MIN;
        for(auto it: ump){
            //cout<<it.first<<" "<<it.second<<" "<< ump2[it.first]<<endl;
            if(ans < abs(it.second - ump2[it.first]))
            {
                ans = abs(it.second - ump2[it.first]);
               // cout<<it.first<<" "<<it.second<<" "<< ump2[it.first]<<endl;
            }
        }
        for(auto it: ump3){
          //  cout<<it.first<<" "<<it.second<<" "<< ump2[it.first]<<endl;
            if(ans < abs(it.second - ump4[it.first]))
            {
                ans = abs(it.second - ump4[it.first]);
               // cout<<it.first<<" "<<it.second<<" "<< ump2[it.first]<<endl;
            }
        }
        return ans;
    }
};