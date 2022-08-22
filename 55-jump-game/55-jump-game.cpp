class Solution {
    
public:
    bool canJump(vector<int>& nums) {
    int reach = 0;
        int i,j;
        
        for( int i = 0 ;i<nums.size()&&i<=reach; i++){
            if(i+nums[i]>reach)  reach = max(reach,i+nums[i]);
        }
        
    return reach>=nums.size()-1;
    }
};