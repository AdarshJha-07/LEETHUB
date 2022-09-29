class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        unordered_map<int,int>ump;
        
        for(int i = 0; i<arr.size(); i++) ump[arr[i]] ++;
        
        vector<pair<int,int>>v;
        for(int j = 0; j < arr.size(); j++) 
        {
           
            v.push_back({abs(arr[j]-x) , arr[j]});
        }
        sort(v.begin() , v.end());
        vector<int>ans;
        for( int i = 0; i<k; i++){
      
            
            ans.push_back(v[i].second);
       
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};