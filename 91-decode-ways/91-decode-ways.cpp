class Solution {
    unordered_map<char,char>ump;
    int solve(int i,string s,vector<int>&dp){
        if(i<0)return 1;
       // if(i==0&&s[i]!='0')return 1;
       // else if(i==0)return 0;
        int ans=0;
        if(dp[i]!=-1)return dp[i];
        if(s[i]!='0')
        ans+=solve(i-1,s,dp);

        if(i>0)
        {
           // cout<<(s[i]<='6'&&s[i-1]<='2'&&s[i-1]!='0')<<endl;
            if((s[i]<='6'&&s[i-1]<='2'&&s[i-1]!='0')||(s[i]>='7'&&s[i-1]=='1'))
        ans+=solve(i-2,s,dp);
        }
       return dp[i]=ans; 
    }
public:
    int numDecodings(string s) {
       
         vector<int>dp(s.size(),-1);
     return  solve(s.size()-1,s,dp);   
    }
};