class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size()==1)return 1;
        int i=0,j=1,cnt=1,res=INT_MIN;
        while(j<(int)nums.size())
        {
              
           if(nums[j-1]<nums[j]){
           
               cnt++;
           }
            else {
               cnt=1;
               i=j;
           }  
            res=max(res,cnt);
            j++;
        }
        return res;
    }
};