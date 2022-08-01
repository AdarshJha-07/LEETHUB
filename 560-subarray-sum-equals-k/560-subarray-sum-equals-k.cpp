class Solution {
public:
      int subarraySum(vector<int>& nums, int k) {
       unordered_map<int,int>mp;
          int sum=0; 
          int count=0;
       //   ump[abs(sum)]=1;
          //ump[0]=1;
          mp[sum]=1;
          mp[0]=1;
          for(int i=0;i<nums.size();i++){
              sum+=nums[i];
              
              
              if(mp.find(sum-k)!=mp.end()){
                 // mp[sum-k]++;
                  count+=mp[sum-k];
              }
              mp[sum]++;
              //if(nums[i]==k&&k!=0)count++;
              
          }
 
               
            
return count;}
};