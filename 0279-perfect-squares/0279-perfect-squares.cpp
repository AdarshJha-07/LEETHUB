class Solution {
public:
    int numSquares(int n) {
         unordered_map<int,int>mp;
        
        for(int i = 1; i<=sqrt(n); i++){
            mp[i*i]++;
        }
        queue<int>q;
        q.push(n);
        int steps = 1;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--){
                int u = q.front();
                q.pop();
                for(auto it: mp){
                    int new_val = u - it.first;
                    if(new_val == 0) return steps;
                    else if(new_val < 0) continue;
                    else q.push(new_val);
                }
            }
            steps++;
        }
     return -1;   
    }
};