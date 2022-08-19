class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        
        
        unordered_map<int,int>ump;
    
        priority_queue<int,vector<int>,greater<int>>pq;
        
        for(int i =0 ;i<nums.size(); i++)
        {
            ump[nums[i]]++;
         
        }
        for(auto it:ump)pq.push(it.first);
      
        while(!pq.empty()){
            vector<int>v;
            int a = pq.top();
            v.push_back(a);
            pq.pop();
            while(!pq.empty()&&v.size()<k&&pq.top() == 1+v[v.size()-1]){
                v.push_back(pq.top());
                pq.pop();
            }
            
            if(v.size()<k)return false;
            int mini = INT_MAX;
         for( int i =0 ;i<v.size(); i++){
             mini = min(mini ,ump[v[i]]);
         }
        for( int i =0 ;i<v.size(); i++){
             ump[v[i]]-=mini;
            if(ump[v[i]])pq.push(v[i]);
         }
        
       }
        
      return true;
    }
};