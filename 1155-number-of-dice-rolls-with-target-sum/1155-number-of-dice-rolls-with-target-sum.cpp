class Solution {
 int n,k;
    int mod=1e9+7;
    int solve( int i, int target , vector<vector<int>>&dp){
        if(i == n)
        {
            if(target==0)return 1;
            
            return 0;
        }
       if(dp[i][target]!=-1)return dp[i][target];
        
    long long ways = 0;
        
        for(int x = 1; x<= k;x++){
            if(target>=x)
            ways=(ways%mod+solve( i+1,target-x, dp)%mod)%mod;
        
        }
        return dp[i][target]=ways%mod;
    }
    
public:
    int numRollsToTarget(int n, int k, int target) {
    this->n=n;
    this->k=k;
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solve(0,target,dp);
    }
};