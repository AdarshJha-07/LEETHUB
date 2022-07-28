class Solution {
    int ans=INT_MIN;
    int solve(vector<int>adj[],int u,int  par,string& s){
        
        int l1=0,l2=0;
        
        for(auto it:adj[u]){
            
          
                
         int    x=solve(adj,it,u,s);
            if(s[u]==s[it])continue;
                if(l2<x)l2=x;
                
                if(l2>l1)swap(l1,l2);
               
            
        }
            ans=max(ans,l1+l2+1); 
        ans=max(ans,l1+1);
        return l1+1;
        }
        
      
    
public:
    int longestPath(vector<int>& parent, string s) {
       int n=parent.size();
        vector<int>adj[n];
       for(int i=1 ; i<n ; i++){
           
          // adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
           
       }
        
    int z=solve(adj,0,-1,s);  
        return max(z,ans);
    }
};