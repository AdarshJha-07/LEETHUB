class Solution {
    
    int solve( int l ,int h , vector<vector<int>>&dp ){
            
        if( l >= h )return 0;
        int ans = 1e9;
        if(dp[l][h] != -1)return dp[l][h];
        
        for( int i =l ;i<=h ;i++){
            
             int op1 = i + solve(l, i-1 ,dp);
            
            int op2 = i + solve(i+1 , h ,dp);
           
            ans = min(ans ,max(op1,op2));
            
        }
        
        return dp[l][h] = ans;
    }
    
public:
    int getMoneyAmount(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
       return  solve( 1, n ,dp);
        
    }
};