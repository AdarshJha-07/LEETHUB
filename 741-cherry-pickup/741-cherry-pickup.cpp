class Solution {
    int n;
    int solve( int r1, int c1,int r2 ,int c2 ,vector<vector<int>>& grid,vector<vector<vector<vector<int>>>>&dp){
        
        if(r1 == n-1 && c1 == n-1)return grid[r1][c1];
        
        if( r1>=n || c1>=n ||r2>=n ||c2>=n)return INT_MIN;
        
        if(dp[r1][c1][r2][c2]!=-1)return dp[r1][c1][r2][c2];
        if(grid[r1][c1] == -1|| grid[r2][c2] == -1) return INT_MIN;
        
        int temp = 0;
        if(r1 == r2 && c1 == c2) temp += grid[r1][c1];
        else temp += grid[r1][c1]+grid[r2][c2];
        
        int p1 = solve(r1+1 ,c1 ,r2+1,c2,grid,dp);
        int p2 = solve(r1 ,c1+1 ,r2+1,c2,grid,dp);
        
         int p3 = solve(r1 ,c1+1 ,r2,c2+1,grid,dp);
         int p4 = solve(r1+1 ,c1,r2,c2+1,grid,dp);
        //if(max({p1,p2,p3,p4}) == INT_MIN) return 0;
        return  dp[r1][c1][r2][c2] = temp+max({p1,p2,p3,p4});
        
    }
    
public:
    int cherryPickup(vector<vector<int>>& grid) {
        
        this->n = grid.size();
        vector<vector<vector<vector<int>>>>dp(n,vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(n,-1))));
        
        int ans = solve(0 ,0 ,0, 0,grid,dp);
       
        return max(0,ans);
    }
};