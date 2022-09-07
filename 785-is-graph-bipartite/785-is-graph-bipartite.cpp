class Solution {
    bool dfs( int u ,vector<int>adj[], int par,int c ,vector<int>&vis)
    {
        bool ans = true;
        for(auto it: adj[u]){
          
            if(it == par)continue;
            if(vis[it] == 0)
            {
                if(c == 1)
                {   vis[it] = 2;
                    ans = ans & dfs(it ,adj , u , 2 ,vis);
                }
               else 
               {   vis[it] = 1;
                   ans = ans & dfs(it ,adj, u ,1,vis);
               }
            }
            else 
            {
                if(vis[it] == 1 && c==1)  return false;
                
                else if(vis[it] == 2 && c==2)return false;
                else 
                {
                  continue;   
                }
            }
        }
        
        return ans;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        vector<int>adj[graph.size()];
        
        for( int i = 0 ; i<graph.size(); i++)
        {
            for( auto it:graph[i])
            { 
                adj[i].push_back(it);
                adj[it].push_back(i);
                
            }
        }
     
        vector<int>vis(graph.size(),0);
    
        for( int i = 0;i<graph.size(); i++)
        {    if(vis[i]==0)
            { 
                  vis[i] = 1;
               if(!dfs(i,adj,-1,1,vis))
                  return false; 
            
            }
        }
        return true;
    }
};