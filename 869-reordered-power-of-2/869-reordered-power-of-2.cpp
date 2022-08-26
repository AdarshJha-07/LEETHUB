class Solution {
    string counter( int n){
        string res = to_string(n);
        sort( res.begin() , res.end());
        return res;
    }
public:
    
    bool reorderedPowerOf2(int n) {
      
        string check = counter(n);
        for( int i=0; i<32 ;i++){
            if(check == counter(1<<i))return true;
        }
        return false;
    }
};