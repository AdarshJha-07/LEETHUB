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
    // int ans;
    // void height(TreeNode* root , int op){
    //     if(root == NULL) return;
    //     if(op > ans){
    //         ans = op;
    //     }
    //     height(root->left, op+1);
    //     height(root->right,op+1);
    // }
     TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) 
     {
        if(root == NULL) return NULL;
        if(p == root) return root;
        if(q == root) return root;
        TreeNode * left = lca(root->left,p,q);
        TreeNode * right = lca(root->right,p,q);
        
       if(left == NULL) return right;
        if(right == NULL) return left;
        
        if(left != NULL && right != NULL) return root;
        return NULL;
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
     
        queue<TreeNode*>q;
        q.push(root);
        vector<TreeNode*>ans={root};
        while(!q.empty())
        {
            int sz = q.size();
            vector<TreeNode*>tem;
            while(sz--){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left != NULL)
                {
                    q.push(temp->left);
                    tem.push_back(temp->left);
                }
                if(temp->right != NULL)
                {
                    q.push(temp->right);
                    tem.push_back(temp->right);
                }
            }
            if(tem.size()!=0)
             ans = tem;
        }
       // cout<<ans.size()<<endl;
        if(ans.size() == 1) return ans[0];
        TreeNode* res = lca(root,ans[0],ans[1]);
        for(int i = 2; i<ans.size(); i++){
              res = lca(root,res,ans[i]);
        }
        return res;
    }
};