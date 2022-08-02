class Solution {
public:
    bool isHappy(int n) {
       
        if(n==2||n==3)return false;
        while(true){ int s=0;
             while(n){
                 s+=(n%10)*(n%10);
                 n=n/10;
             }
            if(s==1||s==7)return true;
            else if(s<10)return false;
            n=s;
        }
        return false;
    }
};