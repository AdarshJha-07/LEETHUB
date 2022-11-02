class Solution {
    int m,n;
    int solve(int i , int j, vector<vector<int>>& grid){
        if(i == m-1) 
        {
           
            if(j+1 < n && grid[i][j] == 1 && grid[i][j+1] == 1) return j+1;
            else if( j-1>=0 && grid[i][j] == -1 && grid[i][j-1] == -1) return j-1;
            else return -1;
        }
        
        int t = 0;
        if(grid[i][j] == 1){
             if(j == n-1 || grid[i][j+1] == -1) return -1;
            
            if(grid[i][j+1] == 1){
              return solve(i+1,j+1,grid);
            }else return -1;

            
        }
        else{
            if(j == 0 || grid[i][j-1] == 1) return -1;
            if(grid[i][j-1] == -1){
              return solve(i+1,j-1,grid);
            }
            else return -1;
        }
        return t;
    }
public:
    vector<int> findBall(vector<vector<int>>& grid) {
    this ->m= grid.size();
    this ->n = grid[0].size();

     vector<int>ans;
    // cout<<m<<" "<<n<<endl;
     for(int i = 0; i<n; i++){
         int z = solve(0,i,grid);
         ans.push_back(z);
     }

return ans;
    }
};