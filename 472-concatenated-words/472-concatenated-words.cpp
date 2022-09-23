class Solution {
    int solve(string s,vector<string>& words ,unordered_map<string,int>&ump){
        if( s == "") return 0;
        string temp = "";
        int ans = INT_MIN;
        for( int j = 0; j<s.size(); j++){
            temp += s[j];
            if( ump.find(temp) != ump.end()){
                ans = max(ans , 1 + solve(s.substr(j+1), words, ump));
            }
        }
        return ans;
    }
    
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_map<string,int>ump;
        
        for( int i = 0; i<words.size(); i++){
            ump[words[i]]++;
        }
        
        vector<string>ans;
     for( int i = 0; i<words.size(); i++){
         if(solve(words[i] , words, ump)>=2)
             ans.push_back(words[i]);
     }
        return ans;
    }
};