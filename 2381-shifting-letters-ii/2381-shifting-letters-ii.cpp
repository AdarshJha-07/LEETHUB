class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
       
        vector<int>v(s.size(),0);
        
        for( int i=0; i<shifts.size(); i++){
            if(shifts[i][2] == 1)
            {
                 v[shifts[i][0]]++;
                if(shifts[i][1]+1<v.size())
                  v[shifts[i][1]+1]--;
                               
            }
            else{
                v[shifts[i][0]]--;
                if(shifts[i][1]+1<v.size())
                  v[shifts[i][1]+1]++;
                
            }
            
        }
        
       // cout<<v[0]<<" ";
        for( int i=1 ;i<v.size(); i++)
            v[i] = v[i-1]+v[i];
        
        for( int i=0; i<v.size(); i++){

   int increaseBy=(s[i]-'a'+v[i])%26;
 increaseBy=(increaseBy+26)%26;
           
   s[i]='a'+increaseBy;
        
        } 
      
        return s;
    }
};