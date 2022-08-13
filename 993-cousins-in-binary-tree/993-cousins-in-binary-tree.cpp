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
    bool ans = false;
    vector<TreeNode*>v;
    vector<int>he;
    int flag = 0;
    void solve(TreeNode* root , int h,int x, int y){
        if(root == NULL)return;
        
      
        if(root->val == x || root->val == y){
            he.push_back(h);
            flag=1;
           return ;
        }
        
        solve( root->left ,h+1,x,y);
        solve( root->right, h+1,x,y); 
        if(flag && root->val!=x && root->val!=y){
            v.push_back( root);
            
            flag=0;
        }
        
        
    }
    
    
public:
    bool isCousins(TreeNode* root, int x, int y) {
       solve( root,0,x,y);
        if(he.size()==1)return false;
        if(he[0]!=he[1])return false;
        
        if(v.size()==1)return false;
        
        return true;
        
    }
};