class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
     
        vector<int>adj[graph.size()];
        vector<int>indegree(graph.size(),0);
         vector<int>outdegree(graph.size(),0);
        
        for( int i= 0; i<graph.size(); i++){
           
            for( auto it:  graph[i])
            {
                adj[it].push_back(i);
              
                outdegree[i]++;
            }
        }
          queue<int>q;
        
        for( int i = outdegree.size() - 1; i>=0; i--)
        {
            if(outdegree[i] == 0)q.push(i);
        }
        
        vector<int>ans;
        vector<int>vis(graph.size(),0);
        while(!q.empty())
        {
            
            int u = q.front();
            q.pop();
           // ans.push_back(u);
            vis[u] = 1;
            for( auto it: adj[u]){
             
                if(--outdegree[it] == 0) q.push(it);
            }
            
        }
      
      for( int i =0; i<vis.size(); i++){
          if(vis[i] == 1) ans.push_back(i);
      }
        
        return ans;
    }
};