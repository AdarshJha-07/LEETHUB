class Solution {
    int n;
    int mod=1e9 +7;
    int solve( int i, char prev , vector<vector<int>>&dp){
        
        if( i == n) return 1;
        
        if( dp[i][prev - '`'] != -1 )return dp[i][prev - '`'];
        
        long long ans = 0;
        
        if(prev=='`'|| prev =='i'){
            ans += solve( i+1, 'a' ,dp)%mod;
            ans += solve( i+1, 'e' ,dp)%mod;
           if(prev != 'i') ans += solve( i+1, 'i' ,dp)%mod;
            ans += solve( i+1, 'o' ,dp)%mod;
            ans += solve( i+1, 'u' ,dp)%mod;
            
        }
        else{
            
            if( prev =='a')
                ans+=solve( i+1, 'e' ,dp)%mod;
            else if( prev == 'e')
                ans += solve( i+1, 'a' ,dp)%mod+ solve( i+1 ,'i' ,dp)%mod;
            else if( prev == 'o')
                 ans += solve( i+1, 'i' ,dp)%mod + solve( i+1, 'u' ,dp)%mod;
            else if( prev == 'u')
                ans += solve( i+1, 'a' ,dp)%mod;
            
            
            
        }
    
     return  dp[i][ prev - '`'] = ans%mod;   
    }
    
public:
    int countVowelPermutation(int n) {
        this->n = n;
        
        vector<vector<int>>dp(n+1,vector<int>(28, -1));
         return solve(0, '`',dp);
    }
};