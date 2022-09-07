class Solution {
    int n;
    int solve( int i ,vector<int>&v){
    
        if( i == n+1) return 1;
        
        int ans  = 0;
        for( int k = 1 ;k<=n ;k++)
        {
            if( ( k%i==0 || i%k==0)&&find(v.begin(),v.end(),k) == v.end())
            {
              v[i] = k;
             ans += solve(i+1 ,v);
                v[i] = 0;
            }
        }
        return ans;
    }
public:
    int countArrangement(int n) {
      
     this -> n=n;
        vector<int>v(n+1,0);
       return solve(1,v); 
    }
};