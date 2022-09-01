class Solution {
    int solve(vector<int>&days,vector<int>&costs,int i,int safe,vector<vector<int>>&dp) 
    {
     //   cout<<safe<<endl;
        if(i==days.size()){
            
         return 0;
        }
        int ans=INT_MAX;
         if(dp[i][safe]!=-1)return dp[i][safe];
        
        if(days[i]<=safe)
        ans=min(ans,solve(days,costs,i+1,safe,dp));  
        
      
        if(days[i]>safe)
        {
            ans=min(ans,solve(days,costs,i+1,days[i],dp)+costs[0]);
         
          ans=min(ans,solve(days,costs,i+1,days[i]+6,dp)+costs[1]);
   
          ans=min(ans,solve(days,costs,i+1,days[i]+29,dp)+costs[2]);
         
         
       }
        return dp[i][safe]= ans;
      //  return 0;
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int s=0;
      
        int n = days.size();
        
        vector<vector<int>>dp(n+2,vector<int>(400,-1));
        return solve(days,costs,0,0,dp);
        
        
    }
};