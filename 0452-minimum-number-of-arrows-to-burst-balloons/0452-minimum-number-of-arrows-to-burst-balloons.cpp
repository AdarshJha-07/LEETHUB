class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
     
        sort(points.begin(),points.end());
        int cnt = 0;
        int end = INT_MAX;
       for(auto it: points){
           if(it[0] > end){
               cnt++;
               end = it[1];
           }
           else {end = min(end,it[1]);}
       }
        
        return cnt+1;
    }
};