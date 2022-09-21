class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& que) {
        
        unordered_map<int,int>ump;
        int even_sum = 0;
        for( int i = 0; i<nums.size(); i++){
            if(nums[i] % 2 == 0)
              {
                ump[nums[i]]++;
                even_sum += nums[i];
              }
        }
        
        vector<int>ans(que.size() ,0);
        for( int i = 0; i<que.size(); i++){
                int prev = nums[que[i][1]];
                nums[que[i][1]] +=   que[i][0];
                
                if( nums[que[i][1]] % 2 == 0)
                {
                    if( prev % 2 == 0){
                        even_sum = even_sum - prev + nums[que[i][1]] ;
                        //ump[prev]--;
                        //if(ump[prev] == 0) ump.erase(prev);
                        
                    }
                    else{
                        even_sum += nums[que[i][1]];
                       
                    } 
                   // ump[nums[que[i][1]]]++;
                
                }
                else
                {
                    if( prev % 2 == 0){
                        even_sum = even_sum - prev;
//                         ump[prev]--;
//                         if(ump[prev] == 0) ump.erase(prev);
                        
                    }
            
                }
            
            
        ans[i] = even_sum;    
            
        }
        
        return ans;
    }
};