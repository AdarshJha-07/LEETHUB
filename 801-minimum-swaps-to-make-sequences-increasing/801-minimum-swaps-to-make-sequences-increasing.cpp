class Solution {
    int solve(int i,bool swapp,vector<int>& nums1,vector<int>& nums2,vector<vector<int>>&dp){
        
        if(i==nums1.size())return 0;
        if(dp[i][swapp]!=-1)return dp[i][swapp];
        int ans=INT_MAX;
    int prev1=nums1[i-1];
        int prev2=nums2[i-1];
        
        if(swapp) swap(prev1,prev2);
        if(nums1[i]>prev1&&nums2[i]>prev2){
            ans=solve(i+1,0,nums1,nums2,dp);
        }
      
        if(nums1[i]>prev2&&nums2[i]>prev1){
            ans=min(ans,1+solve(i+1,1,nums1,nums2,dp));
        }
        return dp[i][swapp]=ans;
    }
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
      nums1.insert(nums1.begin(),-1);  
      nums2.insert(nums2.begin(),-1); 
        int n=nums1.size();
       vector<vector<int>>dp(n,vector<int>(2,-1));
        int x=solve(1,0,nums1,nums2,dp);
       
        return x;
    } 
};