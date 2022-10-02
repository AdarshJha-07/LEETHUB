class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        
     int n=nums1.size();
        int suma=0,sumb=0;
             int curr1=0,mx=INT_MIN,curr2=0;
        for(int it=0;it<n;it++){
            suma+=nums1[it];
            curr1+=(nums1[it]);
    
            curr2+=nums2[it];
            sumb+=nums2[it];
            if(mx<curr1-curr2){
                mx=curr1-curr2;
                
            }
            if(curr1-curr2<0){
                curr1=curr2=0;}
        }
        int mx2=INT_MIN;
        curr1=0;
        curr2=0;
         for(int it=0;it<n;it++){
            curr1+=(nums1[it]);
            curr2+=nums2[it];
            mx2=max(mx2,(curr2-curr1));
            if(curr2-curr1<0){
                curr1=curr2=0;}
        }
   

      int l1=suma-mx;
      int l2=sumb+mx;
      
  
  
         int  l3=suma+mx2;
         int   l4=sumb-mx2;
        return max(max(suma,sumb),max(max(l1,l2),max(l3,l4)));
    
    }
        
    
};