class Solution {
    int k;
    int solve(int i,vector<int>& arr,vector<int>&dp){
        if(i==(int)arr.size())return 0;
        
        if(dp[i]!=-1)return dp[i];
        int ans=INT_MIN;
        int sum=0,len=0;
        int maxi=INT_MIN;
        for(int ind=i; ind< min((int)arr.size(),i+k); ind++){
            len++;
            maxi=max(maxi,arr[ind]);
            sum=solve(ind+1,arr,dp)+len*maxi;
            ans=max(ans,sum);
        }
        return dp[i]=ans;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        this->k=k;
        vector<int>dp(arr.size(),-1);
        return solve(0,arr,dp);
        
    }
};