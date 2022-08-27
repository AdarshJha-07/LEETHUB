class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        int res =0;
        int close = INT_MAX;
        
        for( int i = 0; i<nums.size()-1; i++ ){
             int tar = target - nums[i];
            
            int j = i+1, h = nums.size() - 1;
            
            while( j<h )
            {
                 if( close > abs(target - nums[i] -nums[j]-nums[h]))
            {
                close = abs(target - nums[i] -nums[j]-nums[h]);
                res = nums[i] + nums[j] +nums[h];
            }
                
            if( nums[j] + nums[h] <tar) 
            {
                j++;
            }   
           
            else{
                    h--;
                }
            }
            
            
        }
        return res;
    }
};