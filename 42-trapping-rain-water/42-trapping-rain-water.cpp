class Solution {
    
public:
    int trap(vector<int>& arr) {
       int n=arr.size();     
vector<long long>next(n);//nextLargerElement(arr,n);
vector<long long>prev(n);//prevLargerElement(arr,n);
     //for(auto it:next)cout<<it<<endl;
  

  next[0]=arr[0];
  for(int i=1;i<n;i++){
      if(arr[i]>next[i-1])
      next[i]=arr[i];
      else
      next[i]=next[i-1];
  }
  //for(auto it:next)cout<<it<<endl;
    
  
  prev[n-1]=arr[n-1];
  for(int j=n-2;j>=0;j--){
      if(arr[j]>prev[j+1])
      prev[j]=arr[j];
      else
      prev[j]=prev[j+1];
  }
  //cout<<"gg";
  //for(auto it:prev)cout<<it<<endl;
 long long ans=0;
 
 
  for(int i=1;i<n-1;i++)
{
    if(arr[i]<next[i]&&arr[i]<prev[i])
    ans+=  min(next[i],prev[i])-arr[i];
}  
  return ans;
}
    
};