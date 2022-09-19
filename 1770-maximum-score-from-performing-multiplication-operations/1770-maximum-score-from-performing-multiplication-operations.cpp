class Solution {
    
    //int dp[1001][1001];
    vector<vector<int>>dp;
    int solve( int i ,int low,int high, vector<int>& mul,vector<int>& nums)
    
    {
        if( i == mul.size()) return 0;
        if(dp[i][low] != INT_MIN) return dp[i][low];
        int op1 = mul[i] * nums[low] + solve( i+1 , low + 1, high , mul , nums);
        
        int op2 = mul[i] * nums[high] + solve( i+1 , low , high - 1, mul ,nums);
        
        return  dp[i][low] = max(op1 ,op2);
    }
public:
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        //memset( dp , -1001 , sizeof(dp));
        
        dp = vector<vector<int>>(1001,vector<int>(1001 , INT_MIN));
        return solve( 0 , 0 ,nums.size()-1, mul, nums);
    }
};