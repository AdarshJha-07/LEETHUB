class Solution {
    
    bool check(int mid,vector<int>&stones){
        
        int i = 0;
        int pos = i;
        int flag = 0;
        int n = stones.size();
        vector<int>f(n,0);
        set<int>seen;
        
        while(pos <n){
            pos = upper_bound(stones.begin()+pos,stones.end(),stones[pos] + mid)-stones.begin();
           
            pos--;
            
            if(pos == stones.size()-1){
                flag = 1;
                break;
            }
           /// if(seen.find(pos) !=  seen.end()) return false;
            if(f[pos]) return false;
            //seen.insert(pos);
            f[pos] = 1;
        }
        
        vector<int>rev;
        for(int i = 0; i<n; i++){
            if(f[i] == 0){
                rev.push_back(stones[i]);
            }
        }
        if(flag == 1){
            
           for(int i = 1; i<rev.size(); i++){
               if(rev[i] - rev[i-1] > mid) return false;
           }
        }
        
        return true;
    }
public:
    int maxJump(vector<int>& stones) {
        int low = 0;
        int n = stones.size();
        int high = stones[n-1]-stones[0];
        int mid = (low + high)/2;
        while(low <= high){
            if(check(mid,stones)){
                high = mid-1;
            }
            else low = mid+1;
                
        mid = (low + high)/2;
        }
        
        return low;
    }
};