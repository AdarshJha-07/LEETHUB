class Solution {
    vector<vector<int>>ans;
    
    set<vector<int>>st;
    
    void solve(int i ,vector<int>& nums)
    {
        if( i==nums.size() ) {
            st.insert(nums);
            return;
        }
        
        for( int j = i; j<nums.size(); j++){  
            
            swap(nums[j], nums[i]);
            solve( i+1, nums);
            swap(nums[i], nums[j]);
            
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
     
        solve( 0, nums);
        for( auto it: st){
            ans.push_back(it);
        }
        return ans;
    }
};