class Solution {
    int n;
    int solve( int i , int j, vector<vector<int>>& grid ,vector<vector<int>>&dp){
        
        if( i == n)return 0;
        if(dp[i][j] != -1)return dp[i][j];
    
        int op1 = 1e9;
        for( int k = 0; k<n ; k++){
            if( k!=j){
                op1 = min(op1 , grid[i][j] + solve( i+1 , k ,grid ,dp));
            }
        }
      
        
        return  dp[i][j] = op1;
    }
    
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        this->n = grid.size();
        vector<vector<int>>dp( n+1 ,vector<int>( n+1 ,-1));
        
        int ans = 1e9;
         if(n == 1)return grid[0][0];
        
        for( int j = 0; j<n; j++)
        ans = min(ans ,solve( 0 , j ,grid ,dp));
      
   
        return ans;
    }
};