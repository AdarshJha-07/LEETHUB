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
                indegree[it]++;
                outdegree[i]++;
            }
        }
          queue<int>q;
        
        for( int i = 0; i<outdegree.size(); i++)
        {
            if(outdegree[i] == 0)q.push(i);
        }
        
        vector<int>ans;
        
        while(!q.empty()){
            
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for( auto it: adj[u]){
             
                if(--outdegree[it] == 0) q.push(it);
            }
            
        }
      
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};