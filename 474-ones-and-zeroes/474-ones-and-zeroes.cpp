class Solution {
    pair<int,int> zeroAndOne(string s){
        
        int cnt1 = 0,cnt0 = 0;
        for(int i =0; i<s.size() ;i++){
            if( s[i]=='1' ) cnt1++;
            else cnt0++;
        }
        pair<int,int>ans;
        ans.first = cnt0;
        ans.second = cnt1;
        return ans;
    }
    
    int solve( int i ,int m ,int n,vector<string>& strs ,unordered_map<int ,pair<int,int>>&ump, vector<vector<vector<int>>>&dp){
        
        if( i == strs.size())
            return 0;
        
        if(dp[i][m][n] != -1 )return dp[i][m][n];
        int op1 = INT_MIN;
       
        if( m>=ump[i].first && n>=ump[i].second ) 
         op1 = 1 + solve( i+1 , m-ump[i].first , n - ump[i].second ,strs ,ump ,dp);
        
        int op2 =  solve( i+1 ,m , n, strs, ump ,dp);
        
        return dp[i][m][n] = max(op1 ,op2); 
    }
    
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        unordered_map<int ,pair<int,int>>ump;
        
        for( int i =0 ; i<strs.size() ;i++ ){
            auto t = zeroAndOne(strs[i]);
            ump[i] = t;
        }
        
        vector<vector<vector<int>>>dp( strs.size() ,vector<vector<int>>( m + 1, vector<int>( n + 1 ,-1)));
        
        int ans = solve( 0 , m, n, strs ,ump ,dp);
        return ans;
    }
};