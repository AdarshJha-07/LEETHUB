class Solution {
    int solve(int i,int prev,vector<int>&nums,vector<vector<int>>&dp){
        
        if(i>=nums.size())return 0;
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
          int l1=0;
           if(prev==-1||prev!=i-1)
         l1=solve(i+2,i,nums,dp)+nums[i];
        
        int l2=solve(i+1,prev,nums,dp);
        
        
        return dp[i][prev+1]=max(l1,l2);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        
     return solve(0,-1,nums,dp);   
    }
};