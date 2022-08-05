class Solution {
    int tar;
    vector<int>dp;
    int solve(  vector<int>& nums, int sum){
      if(sum<0)return 0;
      if(sum==0)return 1;
        if(dp[sum]!=-1)return dp[sum];
       int l=0,r=0;
        for( int k=0; k<nums.size() ;k++)
        {
       
          if(sum>=nums[k])
        { 
                l+=solve(nums,sum-nums[k]);
        }  
         
      }
      
        return dp[sum]=l;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
         dp=vector<int>(1001,-1);
        return solve(nums,target);
    }
};