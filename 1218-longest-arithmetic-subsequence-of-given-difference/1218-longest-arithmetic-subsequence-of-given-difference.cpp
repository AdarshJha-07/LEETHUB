class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
     
         //vector<int>dp(n,0);
        unordered_map<int,int>mp;
        
        int n = arr.size();
        for(int i = 0; i<n; i++){
            if(mp.find(arr[i] - diff) != mp.end()){
                mp[arr[i]] = mp[arr[i]-diff]+1;
            }
            else mp[arr[i]] = 1;
        }
        int maxi = INT_MIN;
        for(auto it: mp){
            // cout<<it.first<<" "<<it.second;
            maxi = max(maxi , it.second);
        }
        return maxi ;
    }
};