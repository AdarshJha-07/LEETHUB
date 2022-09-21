class Solution {
    bool solve(int i ,string s, unordered_map<string,int>ump ,vector<int>&dp)
    {
        if(i == s.size()) 
        { 
            return true;
        }
        string temp= "";
        if( dp[i] != -1) return dp[i];
        bool ans = false;
        for( int k = i; k<s.size(); k++)
        {
            temp += s[k];
            if(ump.find(temp) != ump.end())
            {
                ans = ans | solve(k+1 ,s ,ump,dp);
            }
        }
        
        return dp[i] = ans;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
     
        unordered_map<string,int>ump;
        
        for( int i = 0; i<wordDict.size(); i++)
        {
            ump[wordDict[i]]++;
        }
        vector<int>dp(s.size() ,-1);
        return solve(0, s, ump ,dp);
    }
};