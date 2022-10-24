class Solution {
    void in(unordered_set<char>&st,string s){
        for(int i = 0; i<s.size(); i++){
            st.insert(s[i]);
        }
    }
public:
    int maxLength(vector<string>& arr) {
    
    int n = arr.size();
    int mask2 = (1<<n);
    int res = INT_MIN;
     for(int i = 1; i<mask2; i++){
         unordered_set<char>st;
         bool vis[26] = {0};
         int sz = 0;
         bool flag = false;
           for(int j = 0; j<n; j++){
               if(i&(1<<j)){
               
                   for(char c : arr[j]){
                       if(vis[c-'a'])
                       {
                           flag = true;
                           break;
                       }
                       vis[c-'a'] = 1;
                       sz ++;
                   }
                   
               }
           }
          if(!flag && sz>res) res = sz;
     }
     if(res == INT_MIN) res = 0;
      return res;  
    }
};