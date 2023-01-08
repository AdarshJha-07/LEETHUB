class Solution {
    long long check(long long mid,vector<int>& st, int r, int ke){
        int n = st.size();
        vector<long long>pre(n,0);
        int k = n/2;
        int i = k-1;
        int j = k+1;
        int cnt = 0;
        long long ans = 0;
        while(i>=0 && cnt != r){
            ans += st[i--];
            cnt++;
        }
        
        cnt = 0;
        while(j<n && cnt != r)
        {
            ans += st[j++];
            cnt++;
        }
        j--;
        i++;
        int ri  = j,l = i;
        ans += st[k];
         pre[k] = ans;
        
        int t = k-1;
        while(t>=0){
            
            if(i>0)pre[t--] = pre[t+1] + st[--i] - st[j--];
            else if(j>r) pre[t--] = pre[t+1] - st[j--];
            else if(j<=r) pre[t--] = pre[t+1];
            
           
        }
        t = k+1;
        while(t<n){
            if(ri<n-1) pre[t++] = pre[t-1] + st[++ri]-st[l++];
            else if(l<n-r-1)   pre[t++] =  pre[t-1] - st[l++];
            else if(l>= n-1-r) pre[t++] = pre[t-1] ;
          //  cout<<ri<<" "<<l<<" "<<t<<endl;
        }
     
        // for(auto it: pre)cout<<it<<" ";
        // cout<<endl;
        long long sum_extra = 0;
      
        
        vector<long long>mp(n,0);
        for(int i = 0; i<n; i++){
            sum_extra  -= mp[i];
            
            if(pre[i]+sum_extra  >= mid){continue;}
        
            else 
            { long long diff = mid - (pre[i]+sum_extra );
             //if(mid == 6)cout<<diff<<endl;
             if(diff > ke){
                 return false;
             }   
             ke -= diff;
             sum_extra  += diff;
             
             if(i + (2*r)+1 <n){
                 mp[i + (2*r)+1] = diff;
             }
            }
            
        }
 //if(mid == 6)cout<<"pos"<<endl;
        
 return true;
    }
    
public:
    long long maxPower(vector<int>& st, int r, int k) {
        // if(r == 0) return *min_element(st.begin(),st.end());
        long long low = 0,high= 1e15;
       long long mid = low + (high - low)/2;
        
        while(low <= high){
            //cout<<low<<" "<<mid<<" "<<high<<endl;
            if(check(mid,st,r,k)){
                 low = mid+1; 
            }
            else  high = mid -1;
                
        mid = low + (high - low)/2;
        }
        
        return high;
    }
};