class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int i = 0 ,j = 0;
        long long run_sum = 0;
        long long ans = 0;
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int j = 0; j<n; j++){
            run_sum += nums[j];
         if(mp.find(nums[j]) == mp.end()){
             mp[nums[j]]++;
         }
         else{
             while(nums[i] != nums[j]){
                 mp[nums[i]]--;
                 if(mp[nums[i]] == 0)mp.erase(nums[i]);
                 run_sum -= nums[i];
                 i++;
             }
             // mp[nums[i]]--;
            //   if(mp[nums[i]] == 0)mp.erase(nums[i]);

              run_sum -= nums[i];
             i++;
         }
        while(j-i+1 >k){
             mp[nums[i]]--;
             if(mp[nums[i]] == 0)mp.erase(nums[i]);
             run_sum -= nums[i];
             i++;
        }
         
         if(j-i+1 == k){
             if(ans < run_sum){
                 ans = run_sum;
             }
         }
        }
        return ans;
    }
};