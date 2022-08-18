class Solution {
    int ans=0;
    int n;
    int solve( int prev ,int mask ,vector<int>&nums){
        
        if(mask == (1<<n)-1)
            return 1;
        
        int t = 0; 
        for( int i = 0 ;i<nums.size(); i++){
            
            if(prev>=0 &&!isPerfect(nums[i] + nums[prev]))continue;
            
            if(i>0 && nums[i] == nums[i-1] &&(mask&(1<<(i-1))))continue;
            if(!(mask&(1<<i)) ){
                
             
                    t += solve(i , mask|(1<<i), nums);                
            }
        }
        
        return t;
    }
    bool isPerfect(int val){
        int z = sqrt(val);
        
        return z*z == val;
    }
    
public:
    int numSquarefulPerms(vector<int>& nums) {
     
        sort(nums.begin(),nums.end());
        this -> n = nums.size();
        return solve( -1 ,0, nums);
    }
};