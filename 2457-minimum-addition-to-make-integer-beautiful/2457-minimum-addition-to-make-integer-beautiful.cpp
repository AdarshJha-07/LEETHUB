class Solution {
     int sum(long long n) {
        int res = 0;
        while (n) {
            res += n % 10;
            n /= 10;
        }
        return res;
    }
public:
    long long makeIntegerBeautiful(long long n, int target) {
        
      long long temp = 0,base = 1,k = n;
        
       while(sum(n)>target){
           n = n - n%10;
           
           n = n/10;
           n++;
           base *= 10;
       }
      return base*n - k;
    }
};