class Solution {
    
    int extend(int i,vector<int>& nums,int k, vector<int>&vis,int flag){
        int r = i+1,l = i-1;
        int n = nums.size();
        int cnt = 1;
        int ans = 1;
        if(flag == 1)
        while(r<n && k%nums[r] == 0 && nums[r] != k){
            vis[r]=1;
            r++;
            cnt++;
        }
        else 
        while(l>=0 && k%nums[l] == 0)
        {   
            vis[l]=1;
            l--;
            cnt++;
        }
    
        return cnt;
    }
public:
    int subarrayLCM(vector<int>& nums, int k) {
          
       int ans = 0;
        int n=nums.size();
        vector<int>vis(n,0);
         for(int i = 0; i<nums.size(); i++){
              if(nums[i] == k)
              {
                  int cnt1 = extend(i,nums,k,vis,1);
                  int cnt2 = extend(i,nums,k,vis,-1);
                  ans += cnt1*cnt2;
              }
         }
        int res = 0;
        return ans;
    }
};