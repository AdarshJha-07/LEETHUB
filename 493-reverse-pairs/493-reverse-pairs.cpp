class Solution {
    int cnt=0;
    void merge(int l,int m,int h,vector<int>& nums){
        
     
     
         int n1=m-l+1;
         int n2=h-m;
        int arr1[n1],arr2[n2];
        for(int i=0;i<n1;i++)arr1[i]=nums[i+l];
        for(int i=0;i<n2;i++)arr2[i]=nums[m+i+1];
           int i=0,j=0,k=l;
     
        while(i< n1&&j< n2){
            //if(arr1[i]>arr2[j]){
                if((long long)arr1[i]>1LL*2*arr2[j])
                { cnt+=n1-i;
                  j++;
                
                }
                else {
                    i++;
                }
              
                
                
            }
        
          sort(nums.begin()+l,nums.begin()+h+1); 
        

    
    }
    
    
    void mergeSort(int l,int h,vector<int>& nums){
        if(l<h){
            int mid=(l+h)>>1;
            mergeSort(l,mid,nums);
            mergeSort(mid+1,h,nums);
            merge(l,mid,h,nums);
        }
    }
public:
    int reversePairs(vector<int>& nums) {
        mergeSort(0,nums.size()-1,nums);
       // for(auto it:nums)cout<<it<<endl;
        return cnt;
    }
};