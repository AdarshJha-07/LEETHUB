class Solution {
    long long total_sum;
    // int k;
    int mod = 1000000007;
    long long pow(long long a,long long b){
        if(b == 0) return 1;
       // if(b == 1) return a;
        
        if(b%2 == 0){
            long long z = pow(a,b/2);        
            return  (z*z)%mod;
        }
        
        return ((pow(a,(b-1)))*a)%mod;
    }
    
    
    
    long long solve(int i,int k,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(i<0){
           return 1;
        }
        if(dp[i][k] != -1) return dp[i][k];
        long long op1 = solve(i-1,k,nums,dp)%mod;
        long long op2 = 0;
        if(k > nums[i])
        {
            op2 = solve(i-1,k-nums[i],nums,dp)%mod;
        }        
        
        return dp[i][k] = (op1+op2)%mod;
    }
public:
    int countPartitions(vector<int>& nums, int k) { 
        int n = nums.size();
        // total_sum = accumulate(nums.begin(),nums.end(),0);
        for(int i = 0; i< n ; i++){
            total_sum += nums[i];
        }
        
       if(total_sum < 2*k) return 0;
        
       
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        long long X = solve(n-1,k,nums,dp);
        
       
        long long total = pow(2,n);
    
    
        total -= 2*X;
        total = (total%mod + mod)%mod;
       
        return total;
    }
};