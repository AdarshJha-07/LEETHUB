class Solution {
    int n , k;
    vector<int>ans;
    set<int>st;
    void solve( int i , int op){
        
        if( i == n-1)
        {
           // ans.push_back(op);
            st.insert(op);
            return;
        }
        
        int last = op%10;
        if(last + k <= 9)
           solve( i+1 ,op*10 + last + k );
        
        if(last - k >= 0)
            solve( i+1 , op*10 +last - k);
        
        
    }
    
public:
    vector<int> numsSameConsecDiff(int n, int k) {
     
        this->n = n;
        this->k = k;
        for( int i = 1 ; i<=9;  i++){
            solve(0 , i);
        }
        
        for(auto it: st){
            ans.push_back(it);
        }
        return ans;
    }
};