class Solution {
    class Trie
    {
      public: 
        char c;
        Trie *children[26];    
        int cnt = 0;
        
    };
    
    Trie * getNode()
    {
        Trie * temp = new Trie;
        for( int i = 0; i<26; i++){
            temp -> children[i] = NULL;
        }
        
        return temp;
    }
    Trie * insert(Trie * root, string s )
    {
        
        Trie * temp = root;
        for( int i = 0; i<s.size(); i++)
        {
            
            if( temp -> children[s[i] - 'a'])
            {
                temp = temp -> children[s[i]-'a'];
                
            }
            else{
                temp -> children[s[i] - 'a'] = getNode();
                temp -> children[s[i] - 'a']->c = s[i];
                temp = temp -> children[s[i] - 'a'];
            }
            temp->cnt ++;
            
        }
        
        return root;
    }
   int search(Trie * root , string s){
       
       int ans  = 0;
       Trie * temp = root;
       for( int i = 0; i<s.size(); i++)
       {
           temp = temp -> children[s[i]-'a'];
           ans += temp -> cnt;
       }
       return ans;
   }
    
    
    
public:
    vector<int> sumPrefixScores(vector<string>& words) {
     
        Trie * root = getNode();
          
        for( auto it: words)insert(root,it);
        
        vector<int>ans;
        for( auto it: words){
            ans.push_back(search(root,it));
        }
        
        return ans;
    }
};