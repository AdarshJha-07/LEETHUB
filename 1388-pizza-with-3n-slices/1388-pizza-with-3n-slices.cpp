class Solution {
 
    int solve(int i,int end,int n,vector<int>& slices ,vector<vector<int>>&dp){
        
        if(n==0||i>end)return 0;
        if(dp[i][n]!=-1)return dp[i][n];
        int t1=solve(i+2,end,n-1,slices,dp)+slices[i];
        int t2=solve(i+1,end,n,slices,dp);
        
        
        return  dp[i][n]=max(t1,t2);
    }
public:
    int maxSizeSlices(vector<int>& slices) {
       
        int k=slices.size();
    vector<vector<int>>dp(k,vector<int>(k/3+1,-1));
        int first1=solve(0,k-2,k/3,slices,dp);
          dp=vector<vector<int>>(k,vector<int>(k/3+1,-1));
         int first2=solve(1,k-1,k/3,slices,dp);
        return max(first1,first2);
    }
};