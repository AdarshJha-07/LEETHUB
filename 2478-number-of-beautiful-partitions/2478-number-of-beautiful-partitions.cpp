class Solution {
    bool check(char c)
    {
        return c == '2'|| c == '3'|| c == '5'|| c=='7';
    }
    int minL;
    int mod;
    int solve(int i,int k,string& s,vector<vector<long long>>&dp){
        if(i == s.size()){
            if(k == 0) return 1;
            return 0;
        }
        
        if(i + k*minL> s.size() || !check(s[i]) || k<=0 ) return 0;
        if(dp[i][k] != -1) return dp[i][k];
        long long ans = 0;
        for(int j = minL+i-1; j<s.size(); j++)
        {
              if(!check(s[j]))
               ans += solve(j+1,k-1,s,dp)%mod;         
              
        }
        
        return dp[i][k] = ans%mod;
    }
public:
    int beautifulPartitions(string s, int k, int minLength) {
        minL = minLength;
        mod = 1e9+7;
        vector<vector<long long>>dp(s.size(),vector<long long>(k+1,-1));
    
        return solve(0,k,s,dp); 
    }
};