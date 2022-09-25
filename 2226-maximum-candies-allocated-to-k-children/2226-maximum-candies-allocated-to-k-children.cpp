class Solution {
    bool check( int s ,long long k,vector<int>&arr){
           
        long long m = 0;
        for( int i = arr.size()-1; i>=0; i--)
        {
            m += arr[i]/s;
            if( m>= k) return true;
        }
        return false;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
     
   // sort(candies.begin(),candies.end());
        
    long long ans = 0;
      
    int low = 1,high = *max_element(candies.begin(),candies.end()); 
        int mid = (low + high)>>1;
    while( low <= high)
    {
        //if(mid == 0) return 0;
        if(check(mid ,k ,candies))
        {
            low = mid+1;
        }
        else
        {
            high = mid - 1;
        }
        mid = (low + high)>>1;
    }
    
    return high;
        
  }
};