class Solution {
public:
    int numTrees(int n) {
        
        vector<int>dp(n+2,0);
        dp[1] = 1;
        dp[2] = 1;
        for( int i = 3 ; i<=n+1 ; i++){
            
            for( int j=1; j<i ;j++){
                dp[i] += dp[j]*dp[i-j];
            }
        }
        
        return dp[n+1];
    }
};