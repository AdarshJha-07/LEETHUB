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

    TreeNode * solve(int low, int high, vector<int>& nums){
        
        TreeNode * root = new TreeNode (0);
        if(low<=high)
        {
            
            int mid =(low+high)/2;
            // cout<< low<<" "<<high<< " " <<nums[mid]<<endl;
            root->val = nums[mid];
            
          
            root->left = solve( low,mid-1, nums);
            
            root->right = solve( mid+1, high ,nums );
            
        }
        else return NULL;
        return root;
    }
    
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
          TreeNode *root;
        
        return solve( 0 ,nums.size()-1 ,nums);
    }
};