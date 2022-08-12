class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
     
       vector<int>vis(rooms.size(),0);
        
       queue<int>q;
        q.push(0);
   
        while(!q.empty()){
            int u = q.front();
            q.pop();
            vis[u]= 1;
            
            for( int j=0; j<rooms[u].size();j++ ){
                if(!vis[rooms[u][j]])
                    q.push( rooms[u][j]);
                
            }
            
        }
        
        for( auto it: vis)
            if(it!=1)return false;
        
        return true;
    }
};