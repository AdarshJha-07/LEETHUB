class Solution {
public:
    int maximumRobots(vector<int>& cT, vector<int>& rC, long long budget) {
        multiset<int>st;
        int ans = 0;
        int i=0;
        long long sum = 0;
        long long cost = 0;
        
        for( int j=0; j<cT.size(); j++){
             
            st.insert(cT[j]);
            sum += rC[j];
            cost = *(--st.end()) + (j-i+1)*1LL*sum;
        
         
              while( i<=j && cost > budget){
                  sum -= rC[i];
                  st.erase(st.find(cT[i]));
                  i++;
                  if( i > j) cost = 0;
                  else{
                      cost = *(rbegin(st)) + (j-i+1)*1LL*(sum);
                      
                  }
                  
              }
                
            ans = max( ans , j - i + 1);
            
            }
        
    return ans;    
    }
};