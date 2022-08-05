class Solution {
public:
    
    int dp[10001][101];
    
    int solve(int n,int k){
        
        
        if(k == 1){
            return n;
        }
        
        if(n <= 1){
            return n;
        }
        
        if(dp[n][k] != -1){
            return dp[n][k];
        }
        
        int ans = INT_MAX;
        
        int st = 1;
        int en = n;
        
        while(st <= en){
            
            int mid = (st + en)/2;
            
            int op1 = 1 + solve(mid - 1,k-1);
            int op2 = 1 + solve(n - mid,k);
            
            ans = min(ans,max(op1,op2));
            
            if(op1 < op2){
                st = mid + 1;
            }
            else{
                en = mid - 1;
            }
            
        }
        
//         for(int i = 1; i <= n; i++){
            
//             int op1 = 1 + solve(i-1,k-1);
//             int op2 = 1 + solve(n-i,k);
            
            
//             ans = min(ans,max(op1,op2));
//         }
        
        return dp[n][k] = ans;
    }
    int superEggDrop(int k, int n) {
        
        memset(dp,-1,sizeof dp);
        
        return solve(n,k);
        
    }
};