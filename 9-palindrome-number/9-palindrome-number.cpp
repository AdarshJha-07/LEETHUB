class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x<0) return false;
        int z = x;
        int rev = 0;
        while(x){
          rev = 1LL*rev*10 + x%10;
            x=x/10;
        }
        if(rev == z) return true;
        
        return false;
    }
};