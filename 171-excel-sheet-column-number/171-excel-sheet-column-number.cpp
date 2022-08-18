class Solution {
public:
    int titleToNumber(string column) {
        int ans =0;
        for( int i= 0;i<column.size() ;i++ ){
           ans = ans*26 + (column[i]-'A'+1);
        }
        return ans;
    }
};