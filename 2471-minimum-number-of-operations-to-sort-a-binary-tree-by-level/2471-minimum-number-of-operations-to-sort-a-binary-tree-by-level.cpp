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
    int dfs(int u,vector<pair<int,int>>&v,vector<int>&visited){
      visited[u]=1;
      
     int temp=v[u].second;
     
     visited[temp]=1;
     
     int cnt=1;
    while(temp!=u){
         cnt++;
         temp=v[temp].second;
         visited[temp]=1;
    }
    return cnt;
}
   static bool cmp(const pair<int,int>&a, const pair<int,int> &b){
        return a.first<b.first;
    }
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    vector<pair<int,int>>v;
	  
	    for(int i=0;i<nums.size();i++){
	         v.push_back({nums[i],i});
	    }
	    sort(v.begin(),v.end(),cmp);
	    int ans=0;
	 vector<int>visited(nums.size(),0);
	 
	 for(int i=0;i<nums.size();i++)
	 {
	     if(!visited[i] && nums[i]!=v[i].first){
	        
	         ans += dfs(i,v,visited)-1;
	       
	     }
	 }
	    
	   return ans; 
	}
public:
    int minimumOperations(TreeNode* root) {
      // int ans = 0;
        queue<TreeNode*>q;
        q.push(root);
        int ans = 0;
        while(!q.empty()){
            int sz = q.size();
            vector<int>v;
            while(sz--){
                TreeNode* temp = q.front();
                q.pop();
                v.push_back(temp->val);
                if(temp->left != NULL)q.push(temp->left);
               if(temp->right != NULL) q.push(temp->right);
            }
            ans += minSwaps(v);
        }
        
    return ans;
    }
};