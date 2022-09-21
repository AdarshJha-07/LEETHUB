class Solution {
    
    vector<string>ans;
    void solve( int i , string op, string s , unordered_map<string,int>&ump)
    { 
        if( i == s.size()) 
        {   
            op.pop_back();
            ans.push_back(op);
            return;
        }
        string temp = "";
        for( int k = i; k<s.size(); k++)
        {
            temp += s[k];
            if( ump.find(temp) != ump.end()){
                
                solve(k+1 ,op+temp+" ",s,ump);
                
            }
            
        }
        
    }
    
public:
    vector<string> wordBreak(string s, vector<string>& word) {
        
        unordered_map<string,int>ump;
       
        for(auto it: word) ump[it]++;
        
        solve(0, "",s, ump);
     
        return ans;
    }
};