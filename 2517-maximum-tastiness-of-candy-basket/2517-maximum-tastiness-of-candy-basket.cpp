class Solution {
    bool isCheck(int mid,int k, vector<int>&price){
       
        int n = price.size();
        int last = price[0],i = 1,cnt = 1;
        while(cnt < k && i < n){
            if(price[i] - last >= mid){
                cnt++;
                last = price[i];
            }
            i++;
        }
        return cnt >= k;
    }
    
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        int n = price.size();
        int low = 0; 
        int high = price[n-1]-price[0];
        
        int mid = (low + (high-low)/2);
        while(low <= high){
         //   cout<<low<<" "<<mid<<" range"<<high<<endl;
            if(isCheck(mid,k,price)){
                low = mid+1;
            }
            else high = mid-1;
                
           mid = (low + (high-low)/2);
        }
        
        return high;
    }
};