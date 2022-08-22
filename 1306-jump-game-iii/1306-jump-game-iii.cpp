class Solution {
public:
    bool canReach(vector<int>& nums, int start) {
     
       int n = nums.size();
        vector<int>vis(nums.size() ,0);
        vis[start] = 1;
        queue<int>q;
        
        q.push(start);
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            if(nums[u] == 0) return true;
            vis[u] = 1;
            if(u + nums[u]<n && !vis[u+ nums[u]])
            {
                q.push(u+nums[u]);
            }
            if(u - nums[u]>=0 && !vis[u - nums[u]])
            {
                q.push(u - nums[u]);
            }
        }
        
        return false;
    }
};