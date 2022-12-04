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
        vector<int>left(n,0);     
        vector<int>right(n,0);
        // cout<<ind<<endl;
        unordered_map<int,int>ump;
           int less = 0,grt = 0;
        for(int i = ind+1; i<n; i++)
        { 
            if(nums[i] < nums[ind])
            {
                less++;
            }
           else
               grt++;
           right[i] = grt - less;
           ump[right[i]]++;
        }
         ump[0]++;
       less = 0,grt = 0;
        int ans = 0;
        if(ump.find(1)!= ump.end()){
              ans += ump[1];
           }
        if(ump.find(0) != ump.end()){
            ans += ump[0];
        }   
        
       for(int i = ind-1; i>= 0; i--){
           if(nums[i] < nums[ind]){
               less++;
           }
           else
               grt++;
           left[i] = grt - less;
           //cout<<left[i]<<" ";
           if(ump.find(1-left[i])!= ump.end()){
              ans += ump[1-left[i]];
           }
           if(ump.find(-left[i]) != ump.end()){
               ans += ump[-left[i]];
           }
           
       }
   
        return ans;
    }
};