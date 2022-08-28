class Solution {
    void solve(vector<vector<int>>& conditions ,int k , vector<int>&topo)
    {
        vector<int>indegree(k+1,0);
        vector<int>adj[k+1];
        for( int i=0 ;i<conditions.size(); i++){
            
            adj[conditions[i][0]].push_back(conditions[i][1]);
            indegree[conditions[i][1]]++;   

        }
        queue<int>q;
        
        for(int i=0; i<=k; i++) if(indegree[i] == 0) q.push(i);  
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            topo.push_back(u);
            for( auto it: adj[u]){
                if(--indegree[it] == 0)q.push(it);
            }
        }
        
    }
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        
        vector<int>topo_row,topo_col;
        
        solve(rowConditions ,k,topo_row);
        solve(colConditions ,k,topo_col);
   
        vector<vector<int>>ans;
        if( topo_row.size()!= k+1||topo_col.size()!= k+1)return ans;
   
       ans = vector<vector<int>>(k ,vector<int>(k,0));
        for( int i=0 ;i<=k; i++){
            
            int u = topo_row[i];
            if(u ==0 )continue;
            int v = find(topo_col.begin() ,topo_col.end(),u) - topo_col.begin();
            
            ans[i-1][v-1] = u;
        }
        return ans;
    }
};