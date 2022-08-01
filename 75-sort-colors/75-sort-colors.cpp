class Solution {
public:
    void sortColors(vector<int>& nums) {
         if(nums.size()==1)return ;
        int n=nums.size();
        int i=0,j=n-1,k=0;
        while(k<=j&&i<j ){
          
            if(nums[k]==1){
                k++;
      
            }
          else  if(nums[k]==0){
                swap(nums[i],nums[k]);
                i++;
              if(k<i)k=i;
                    
            }
            else if(nums[k]==2){
                swap(nums[j],nums[k]);
                j--;
                if(k>j)k=j;
            } 
            
        }
    }
};