class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
    
        int res =0;
        for(int i=0; i<nums.size();i++){
            int curr = 1;
            for(int j=i; j<nums.size();j++){
                curr=lcm(curr,nums[j]);
                if(curr == k)res++;
                if(curr>k)break;
            }
        }
        return res;
    }
};