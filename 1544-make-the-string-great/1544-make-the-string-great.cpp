class Solution {
    string solve(string s){
       //  cout<<s<<endl;
        if(s.size() == 1|| s.size()==0) return s;
        for(int i = 0; i<s.size()-1; i++){
            if(s[i] != s[i+1]){
                if(tolower(s[i]) == tolower(s[i+1])){
                   s = s.substr(0,i)+s.substr(i+2);
                   // cout<<s<<" "<<i<<endl;
                    return solve(s);
                }
            }
        }
        return s;
    }
public:
    string makeGood(string s) {
        if(s.size()== 1) return s;
        return solve(s);
    }
};