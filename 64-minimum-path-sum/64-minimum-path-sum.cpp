class Solution {
    int n ,m;
    int dp[201][201];
    int solve( int i ,int j ,vector<vector<int>>& grid){
        if(i>=n || j>=m)return 1e9;
        if( i== n-1 && j==m-1) return grid[i][j];
        
        if(dp[i][j] != -1)return dp[i][j];
        
        int p1 = grid[i][j] + solve( i+1 ,j, grid);
        
        int p2 = grid[i][j] + solve( i, j+1, grid);
        
        return dp[i][j] = min(p1,p2);
        
    }
    
public:
    int minPathSum(vector<vector<int>>& grid) {
        this->n= grid.size();
        this->m = grid[0].size();
        memset( dp ,-1, sizeof(dp));
        
        return solve( 0 ,0 ,grid);
    }
};