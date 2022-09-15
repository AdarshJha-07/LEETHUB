class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(), changed.end());
          vector<int>res;
        
        if( changed.size() % 2 != 0 ) return res;
        
        unordered_map<int,int>ump;
        vector<int>ans;
        int cnt = 0;
        for( int i = changed.size() -1 ; i>=0; i--){
            if(ump.find(2*changed[i]) != ump.end() )
            { 
               // cout<<changed[i]<<endl;
                ans.push_back(changed[i]);
                cnt++;
                ump[2*changed[i]]--;
                if( ump[2*changed[i]] == 0 )
                    ump.erase(2*changed[i]);
                
            }
            else
             ump[changed[i]]++;
        }
      
      
        return cnt == changed.size()/2 ? ans : res;
    }
};