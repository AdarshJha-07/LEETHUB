class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int l = 0, r = 0;
        int z  = k;
        int ans = INT_MIN;
        
        unordered_map<int,set<int>>ump;
        
        while( r<nums.size() )
        {
            if(nums[r]==1)
            {
                r++;
            }
            else
            {
                if(z>0)
                {
                     z--;
                     ump[0].insert(r);
                     r++;
                }
                else{
                    while(l<r && ump[0].find(l) == ump[0].end())
                    {
                        l++;
                    }
                   if(ump[0].find(l) != ump[0].end()) 
                   {
                       ump[0].erase(l);
                       l++;
                       z++;
                   }
                    else l++,r++;
                    
                }
                
            }
           //  cout<<l<<" "<<r<<endl;
            ans = max(ans , r-l);
        }
        
        return ans;
    }
};