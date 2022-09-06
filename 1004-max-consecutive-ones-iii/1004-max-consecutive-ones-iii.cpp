class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int l = 0, r = 0;
        int z  = k;
        int ans = INT_MIN;
        
        unordered_map<int,int>ump;
        
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
                     // ump[0].insert(r);
                    ump[r]++;
                     r++;
                }
                else{
                    while(l<r && ump[l] == 0)
                    {
                        l++;
                    }
                   if(ump[l]) 
                   {
                      ump[l] = 0;
                       l++;
                       z++;
                   }
                    else l++,r++;
                    
                }
                
            }
         
            ans = max(ans , r-l);
        }
        
        return ans;
    }
};