class Solution {
    vector<vector<int>>ans;
    void solve(vector<int>temp,vector<int>&visited, vector<int>& nums){
     
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
       
        for( int k=0; k<nums.size(); k++ ){
            if(!visited[k]){
                visited[k]=1;
            temp.push_back(nums[k]);
            solve(temp, visited ,nums);
            temp.pop_back();
            visited[k]=0;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
                vector<int>visited(nums.size(),0);
        vector<int>temp;
        solve(temp,visited,nums);
        return ans;
    }
};