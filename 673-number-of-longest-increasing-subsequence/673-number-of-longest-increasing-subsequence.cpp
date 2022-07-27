class Solution {
    public:
//     int cnt=1,maxi=INT_MIN;
//     unordered_map<int,int>ump;
//  int f(int idx, int prev_idx, int n,vector<int>& a, vector<vector<int> >& dp,vector<int>&v)
// {
//     if (idx == n) {
     
//        if((int)v.size()>maxi){
//            maxi=v.size();
           
           
//        }
      
//         ump[(int)v.size()]++;
//         return 0;
//     }
 
//     // if (dp[idx][prev_idx + 1] != -1) {
//     //     return dp[idx][prev_idx + 1];
//     }
 
//     int notTake = 0 + f(idx + 1, prev_idx, n, a, dp,v);
//     int take = INT_MIN;
//     if ( a[idx] > v[v.size()-1]) {
//         v.push_back(a[idx]);
//         take = 1 + f(idx + 1, idx, n, a, dp,v);
//         v.pop_back();
//     }
 
//     return dp[idx][prev_idx + 1] = max(take, notTake);
// }
// public:
//     int findNumberOfLIS(vector<int>& nums) {
//       vector<int>v; 
//         v.insert(v.begin(),-1);
//         int n=nums.size();
//         vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
     
//         int z=f(1,-1,n,nums,dp,v);
//       //  for(auto it:ump)cout<<it.first<<" "<<it.second<<endl;
//         return ump[maxi];
//     }

    
    int findNumberOfLIS(vector<int>& nums) {
        
        
        int n = nums.size();
        
        int dp[n];
         int cnt[n];
        for(int i = 0; i < n; i++){
            dp[i] = 1;
            cnt[i]=1;
        }
     
        
        for(int i = 1; i < n; i++){

            for(int j = i-1; j >= 0; j--){
                if(nums[i] > nums[j] and 1 + dp[j] > dp[i]){
                    dp[i] = 1 + dp[j];
                    //mp[i]++;
                    cnt[i]=cnt[j];
                }
                else if(nums[i]>nums[j] and 1+dp[j]==dp[i]){
                    cnt[i]+=cnt[j];
                }
            }
        }
        
     
        
        int mx = 0;
        
        for(int i = 0; i < n; i++){
            mx = max(mx,dp[i]);
        }
     int ans=0;
       for(int i = 0; i < n; i++){
          if(dp[i]==mx){
              ans+=cnt[i];
          }
        }
        return ans;
     
    }
};