class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& mat) {
        map<int,int>win;
        map<int,int>los;
        for(int i=0;i<mat.size();i++)
        {
          
     
            win[mat[i][0]]++;
     
       
            los[mat[i][1]]++;
       
        
        }
        
        vector<vector<int>>ans;
        vector<int>temp;
        for(auto it:win){
            if(los.find(it.first)==los.end())
                temp.push_back(it.first);
        }
        ans.push_back(temp);
        temp.clear();
        for(auto it:los){
            if(it.second==1)
                temp.push_back(it.first);
        }
        ans.push_back(temp);
        return ans;
        
    }
};