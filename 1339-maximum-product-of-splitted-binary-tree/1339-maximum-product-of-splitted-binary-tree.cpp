// *
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };

class Solution {
  
    unordered_map<TreeNode*,long long>ump;
   
    long long solve(TreeNode * root){
        if(root == NULL) return 0;
         
        int a = solve(root->left);
        int b = solve(root->right);
        
        return  ump[root] = a + b + root->val;
    }    
public:
    int maxProduct(TreeNode* root) {
      long long   sum = solve(root);
      long long   ans = -1; 
        int mod = 1e9+7;
        for(auto it: ump){
            long long z = (it.second*(sum-it.second));
          if(ans < z){
              ans = z;
          }
        }
        return ans%mod;
    }
};