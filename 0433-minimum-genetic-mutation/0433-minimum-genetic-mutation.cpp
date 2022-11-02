class Solution {
    
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string,int>mp;
        int n = start.size();
        
        for(int i =0; i<bank.size(); i++){
            mp[bank[i]]++;
        }
        unordered_map<string,int>vis;
        vis[start]++;
        queue<string>q;
        q.push(start);
        
        int level = 0;
        while(!q.empty())
        {
            int sz = q.size();
            for(int i = 0; i<sz; i++){
                string s = q.front();
                q.pop();
                if(s == end && mp[s]) return level;
               // if(vis[s]) continue;
                
                for(int j = 0; j<n; j++){
                  
                      
                        string temp = s;
                        temp[j] = 'A';
                      if(!vis[temp]&&mp[temp])
                      {   vis[temp]++;
                          q.push(temp);
                      }
                          temp[j] = 'C';
                      if( !vis[temp] && mp[temp]) 
                      {    vis[temp]++;
                          q.push(temp);
                      }
                        temp[j] = 'T';
                      if(!vis[temp] && mp[temp])  
                      {    vis[temp]++;
                          q.push(temp);
                      }
                         temp[j] = 'G';
                      if(!vis[temp] && mp[temp])  
                      {    vis[temp]++;
                          q.push(temp);
                      }
                    
                }
                
            }
            level++;
        }
        
        return -1;
    }
};