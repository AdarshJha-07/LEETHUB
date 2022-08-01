class Solution {
public:
    int findMaxLength(vector<int>& nums) {
         
        int n=nums.size();
        int cnt0 = 0,cnt1 = 0;
      
        unordered_map<int,int>ump;
        for(int i=0 ;i <nums.size() ;i++)
        {
            if(nums[i]==0)
            {
                nums[i]=-1;
            }
          
        }
        int i=0;
      
        int sum=0;
        int ans=INT_MIN;
        ump[sum]=-1;
        for(int i=0; i<n ;i++){
           sum+=nums[i];
           if(ump.find(sum)!=ump.end())
           {
            
               ans=max(ans,i-ump[sum]);
           }
           else
           {
               ump[sum]=i;
           }
        }
        if(ans==INT_MIN)return 0;
        return ans;
    
    }
};