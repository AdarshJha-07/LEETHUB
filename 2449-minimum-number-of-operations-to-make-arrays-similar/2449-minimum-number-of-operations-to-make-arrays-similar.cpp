class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        
        // vector<int>ans;
        multiset<int>ev;
        multiset<int>odd;

            for(int i = 0; i<target.size(); i++)
            {
                if(target[i]%2 == 0)ev.insert(target[i]);
                else odd.insert(target[i]);
            }
        
        vector<int>even;
        vector<int>oder;
        for(int i = 0; i<nums.size(); i++){
             if(nums[i]%2 == 0)even.push_back(nums[i]);
            else oder.push_back(nums[i]);
        }
        
      sort(even.begin(),even.end());
      sort(oder.begin(),oder.end());
        long long ans  = 0;
        for(int i = 0; i<even.size(); i++){
            if(even[i]-*ev.begin() > 0)
            {
                ans += (even[i] - *ev.begin());
               // cout<<even[i]<<" ";
                
            } 
            ev.erase(ev.begin());
        }
        for(int i = 0; i<oder.size(); i++){
            if(oder[i]- *odd.begin() > 0)
            {
                ans += (oder[i] - *odd.begin());
            } 
            odd.erase(odd.begin());
        }
        
      
        return ans/2;
    }
};