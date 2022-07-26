class Solution {
    stack<int>st;
public:
    vector<int> findOrder(int V, vector<vector<int>>& pre) {
           
        vector<int>indegree(V,0);
     vector<int>adj[V];
        for(auto & it:pre){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        queue<int>q;
        vector<int>ans;
        for(int i=0;i<V;i++){
            if(!indegree[i]){
                q.push(i);
      //      ans.push_back(i);
            }
        }
        
   while(!q.empty()){
       int v=q.front();
       q.pop();
       ans.push_back(v);
           for(auto u:adj[v])
        {
                
                indegree[u]--;
                if(indegree[u]==0){
                   
                    q.push(u);
                }
        }}
       if(ans.size()!=V){
         ans.clear();
           return ans;
       }
       
        return ans;
        // vector<vector<int>> G(n);
        // vector<int> degree(n, 0), bfs;
        // for (auto& e : pre)
        //     G[e[1]].push_back(e[0]), degree[e[0]]++;
        // for (int i = 0; i < n; ++i) if (!degree[i]) bfs.push_back(i);
        // for (int i = 0; i < bfs.size(); ++i)
        //     for (int j: G[bfs[i]])
        //         if (--degree[j] == 0) bfs.push_back(j);
        // if(bfs.size() != n){
        //     bfs.clear();
        //     return bfs;
        // }
        // return  bfs;
    }
};