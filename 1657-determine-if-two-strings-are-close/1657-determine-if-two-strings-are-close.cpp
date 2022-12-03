class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int>v1(26,0);
        unordered_map<int,int>mp1;
        vector<int>v2(26,0);
        unordered_map<int,int>mp2;
        set<int>s1,s2;
        for(auto it: word1)
        {
            v1[it-'a']++;
            mp1[it-'a']++;
            s1.insert(it-'a');
           // cout<<it-'a'<<" ";
        }
        for(auto it: word2)
        {
            v2[it-'a']++;
            mp2[it-'a']++;
            s2.insert(it-'a');
        }
        for(auto it = s1.begin(),it2 = s2.begin();  it!= s1.end()&& it2 != s2.end(); it++,it2++){
              if(*it != *it2){
                  return false;
              }
        }
        
        sort(v1.begin(),v1.end());
      
        sort(v2.begin(),v2.end());

        for(int i = 0; i<26; i++){
        
            if(v1[i] != v2[i]) return false;
        }
        return true;
    }
};