class Solution {
    long long k;
    int solve(int i,string& s,vector<int>&dp){
        if(i == s.size()){
            return 0;
        }
        
        if(dp[i] != -1) return dp[i];
        string a;
        int p1 = 1e9;
        long long b = 0;
        for(int j= i; j<(int)s.size(); j++){
            
            b = b*10 + (s[j]-'0');
            if(b <= k){
                p1 = min(p1,1 + solve(j+1,s,dp));
            }else break;
            
        }
        return dp[i] = p1;
    }
    
    
public:
    int minimumPartition(string s, int k) {
        this->k = k;
        vector<int>dp(s.size(),-1);
        int ans = solve(0,s,dp);
        
        if(ans >= 1e9)ans = -1;
        
        return ans;
    }
};