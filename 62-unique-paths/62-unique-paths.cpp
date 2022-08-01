class Solution {
    int m,n;
    int solve(int i,int j,vector<vector<int>>&dp){
        if(i>=m||j>=n)return 0;
        if(i==m-1&&j==n-1)return 1;
          if(dp[i][j]!=-1)return dp[i][j];
        int l1=solve(i+1,j,dp);
        int l2=solve(i,j+1,dp);
        return  dp[i][j]= l1+l2;
    }
public:
    int uniquePaths(int m, int n) {
        this->m=m;
        this->n=n;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(0,0,dp);
    }
};