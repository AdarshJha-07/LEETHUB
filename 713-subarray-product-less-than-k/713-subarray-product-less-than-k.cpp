class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& A, int k) {
    
       
      
       
        int sum=1;
        int l = 0;
        int cnt=0;
        for(int i=0;i<A.size(); i++){
             sum=sum*A[i];
           
               while(l<=i&&sum>=k){
                   sum=sum/A[l++];
              //l++;
                   //su
               }
           
            cnt+=i-l+1;
        }
        return cnt;
    }
};