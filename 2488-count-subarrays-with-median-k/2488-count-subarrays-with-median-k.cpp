class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        
        int ind = 0;
        int n = nums.size();
        for(ind = 0; ind<n; ind++){
            if(nums[ind] == k){
                break;
            }
        }
        // vector<int>left(n,0);     
        // vector<int>right(n,0);
        
        unordered_map<int,int>ump;
          // int less = 0,grt = 0;
        int diff = 0;
        for(int i = ind+1; i<n; i++)
        { 
            if(nums[i] < nums[ind])
            {
                // less++;
                diff--;
            }
           else
               diff++;
        
            
           ump[diff]++;
        }
         ump[0]++;
     //  less = 0,grt = 0;
        diff = 0;
        int ans = 0;
        if(ump.find(1)!= ump.end())
        {
              ans += ump[1];
        }
        if(ump.find(0) != ump.end())
        {
            ans += ump[0];
        }
           
        
       for(int i = ind-1; i>= 0; i--){
           if(nums[i] < nums[ind]){
               diff--;
           }
           else
               diff++;
           //left[i] = grt - less;
           //cout<<left[i]<<" ";
           if(ump.find(1-diff)!= ump.end()){
              ans += ump[1-diff];
           }
           if(ump.find(-diff) != ump.end()){
               ans += ump[-diff];
           }
           
       }
   
        return ans;
    }
};