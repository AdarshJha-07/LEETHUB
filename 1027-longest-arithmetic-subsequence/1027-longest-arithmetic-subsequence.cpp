class Solution {

    
public:
    int longestArithSeqLength(vector<int>& nums) {
        if(nums.size()<=2)return nums.size();
        
        int ans = INT_MIN;
     
        //unordered_map<int,int>dp[nums.size()];
        vector<vector<int>> dp(nums.size(), vector<int>(2000, 0));
       

        for( int i = 1;i<nums.size(); i++){
        
            for( int j=0 ;j<i; j++){
                 int   cnt = 1;
                int diff = nums[i]-nums[j]+1000;
                
                if(dp[j][diff])cnt = dp[j][diff];
                
                
                
                
                dp[i][diff] = max(dp[i][diff],1+cnt);
                
                ans = max(ans ,dp[i][diff]);
            }
            
           
        }
        
        
        return ans;
    }
};