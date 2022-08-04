class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
            for( int i=nums.size()-2; i>=0 ;i--){
                if(nums[i+1]>nums[i]){
                    int mx=i+1;
                    for(int j= i+1; j<nums.size(); j++){
                        if(nums[mx]>nums[j]&&nums[j]>nums[i]){
                         mx=j;   
                        }
                    }
                    swap(nums[mx],nums[i]);
                    sort(nums.begin()+i+1,nums.end());
                    return;
                }
                
            }

        reverse(nums.begin(), nums.end());
    }
};