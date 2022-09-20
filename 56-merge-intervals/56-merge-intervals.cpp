class Solution {
   static bool cmp(const vector<int>&a,const vector<int>&b){
       return a[0]<b[0];
   }
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
       sort( inter.begin() ,inter.end() ,cmp);
    
      vector<vector<int>>ans;
      int a = inter[0][0];
      int b = inter[0][1];
      for( int i = 1; i<inter.size(); i++){
          if( inter[i][0] <= b)
          {
              b =max(b ,inter[i][1]);
          }
          else {
              ans.push_back({a ,b});
              a = inter[i][0];
              b = inter[i][1];
          }
          
      }
        ans.push_back({a , b});
        return ans;
    }
};