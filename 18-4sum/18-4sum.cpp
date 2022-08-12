class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        sort( nums.begin() , nums.end() );
        
        set<vector<int>>st;
        for( int i = 0; i<nums.size(); i++){
            for(int j= i+1; j<nums.size(); j++){
               
                int l = j+1 ,h= nums.size()-1;
                while( l<h ){
                    
                    long long temp = 0;
                    temp += nums[i];
                    temp += nums[j];
                    temp += nums[l];
                    temp += nums[h];
                    
                    if( temp == target )
                    {
                        st.insert({nums[i],nums[j],nums[l],nums[h]});
                        int a1= nums[l],a2=nums[h];
                        while(l<h&&a1==nums[l])l++;
                        while(l<h&&a2==nums[h])h--;
                        
                    }
                    else if( temp<target )
                    {
                        l++;
                    }
                    else h--;
                }
                
            }
        }
        
        vector<vector<int>>ans;
        for( auto it: st){
            ans.push_back(it);
        }
        return ans;
    }
};