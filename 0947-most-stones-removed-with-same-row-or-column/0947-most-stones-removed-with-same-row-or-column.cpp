class Solution {
    vector<int>vis;
    
      int dfs(int i,vector<int>adj[]){
         
          
          vis[i]=1;
          int ans = 0;
         for(auto it: adj[i])
         {
             if(!vis[it])
                ans += 1 + dfs(it,adj);    
         } 
          return ans;
     }
public:
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int>adj[n];
        vis = vector<int>(n,0);
        
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if(stones[i][0] == stones[j][0])
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
                
                if(stones[i][1] == stones[j][1])
                {
                     adj[i].push_back(j);
                     adj[j].push_back(i);
                }                
            }
        }
        
     int ans = 0;
     for(int i= 0; i<n; i++){
         if(!vis[i]){
             ans += dfs(i,adj);
         }
     } 
       return ans;
    }
};