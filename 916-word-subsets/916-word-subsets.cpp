class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {

        unordered_map<char,int>ump;
        string search;
        for( int i=0; i<words2.size(); i++)
        {
            
            vector<int>v(26,0);
            for(int j=0; j<words2[i].size(); j++)
            {
               v[words2[i][j]-'a']++;    
           }
            for(int i=0;i<26; i++){
                if(v[i]>0)
                if(ump.find(char(i+'a'))!=ump.end()){
                   if(ump[char(i+'a')]>=v[i]){
                       continue;
                   }
                    else{
                       
                        int x=v[i]-ump[char(i+'a')]; 
                        ump[char(i+'a')]=v[i];
                        while(x--){
                            search+=char(i+'a');
                           // cout<<char(i+'a');
                        }
                    }
                }
                else{
                     ump[char(i+'a')]=v[i];
                        int x=ump[char(i+'a')];
                        while(x--){
                            search+=char(i+'a');
                           // cout<<char(i+'a');
                        }
                }
            }
            
        }
     
      
        vector<string>ans;
        sort(search.begin(),search.end());
     //  cout<<search<<endl;
        for(int i=0;i<words1.size(); i++)
        {
            string temp=words1[i];
            
             sort(temp.begin(),temp.end());
            
            int n=temp.size();
            
            int m=search.size();
             int x=0,y=0;
            while(x<n&&y<m){
                if( search[y]==temp[x]  ){
                    x++;
                    y++;
                }
                else
                {
                    x++;
                }
            }
            
            if(y==m)ans.push_back(words1[i]);
        }
      
        return ans;
    }
};