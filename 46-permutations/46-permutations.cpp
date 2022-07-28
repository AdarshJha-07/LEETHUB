class Solution {
    vector<vector<int>>ans;
    void solve(int idx,vector<int>&visited, vector<int>& nums){
     
        if(idx>=nums.size()){
           ans.push_back(nums);
            return;
        }
       
        for( int k=idx; k<nums.size(); k++ ){
           
              swap(nums[idx],nums[k]);
              solve(idx+1, visited ,nums);
              swap(nums[idx],nums[k]);
            }
        }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<int>visited(nums.size(),0);
        vector<int>temp;
        solve(0,visited,nums);
        return ans;
    }
};