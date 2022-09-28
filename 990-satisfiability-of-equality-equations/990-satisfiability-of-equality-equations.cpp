class Solution {
    class DSU{ 
    int *parent;
    int *rank;
public:

    DSU(int n){
        
        parent=new int[n];
        rank=new int[n];

        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            rank[i]=0;
        }
    }
    
    int find(int node){
         
        if(node==parent[node]) return node;

        return parent[node]=find(parent[node]);
    }
    
    // Union function 
     void Union(int u,int v){
        
        u=find(u);
        
       
        v=find(v);
        
 
        if(u!=v)
        {
            if(rank[u]<rank[v])
            {
                int temp=u;
                u=v;
                v=temp;
            }
          
            parent[v]=u;
            
            if(rank[u]==rank[v])
                rank[u]++;
        }
    }
};

public:
    bool equationsPossible(vector<string>& equi) {
        DSU d =  DSU(1001);
        
        for( int i = 0; i<equi.size(); i++){
            if(equi[i][1] == '='){
                d.Union(equi[i][0]-'a',equi[i][3]-'a');
            }
        }
        for( int i = 0; i< equi.size(); i++){
            if(equi[i][1] == '!'){
                if(d.find(equi[i][0]-'a') == d.find(equi[i][3]-'a')) return false;
            }
        }
        
        return true;
    }
};