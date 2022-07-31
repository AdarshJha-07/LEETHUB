class Solution {
   
    
public:
    
    
    vector<int> dp;
    
    int ans = 0;
    
    void solve(int u,vector<vector<int>> &adj,vector<int> &vis1,vector<int> &vis2,int cnt){
        
        
        vis1[u] = 1;
        vis2[u] = 1;
        
       
        
        
        for(auto nb : adj[u]){
            
            if(vis1[nb]){
                if(vis2[nb]){
                    
                    ans = max(ans,dp[u] - dp[nb] + 1);
                }
            }
            else{
                
                dp[nb] = cnt;
                
                solve(nb,adj,vis1,vis2,cnt+1);
                
            }
        }
        
        vis2[u] = 0;
    }
    int longestCycle(vector<int>& edges) {
        
        int n=edges.size();
        
        vector<vector<int>> adj(n);
        
        vector<int>vis(n,0);
        vector<int> vis2(n,0);
        
        dp.resize(n,0);
        
        for(int i=0 ;i<n ;i++){
            if(edges[i]!=-1)adj[i].push_back(edges[i]);
        }
        
        for(int i = 0; i < n; i++){
            
            if(!vis[i]){
                dp[i] = 1;
                solve(i,adj,vis,vis2,2);
            }
        }
    
        return ans == 0 ? -1 : ans;
    }
};