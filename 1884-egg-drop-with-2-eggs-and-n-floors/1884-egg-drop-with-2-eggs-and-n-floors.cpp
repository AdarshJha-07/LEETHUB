class Solution {
    int dp[1001][3];
    int solve( int n , int k){ 
       
        
        if( k == 1 )return n;
        if( n<=1 )
             return n;        
        
        
       if(dp[n][k] != -1 ) return dp[n][k];
        
        int ans = INT_MAX;
        for( int i = 1 ; i<= n ;i++){
          int   t1 = 1 + solve( n-i ,k);
          int   t2 = 1 + solve( i-1, k-1);
            
         int z = max( t1, t2);
           ans = min( ans , z); 
        }
        return dp[n][k] = ans;
    }
    
public:
    int twoEggDrop(int n) {
        memset( dp ,-1 ,sizeof dp);
     return solve( n ,2);   
    }
};