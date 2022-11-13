class Solution {
public:
//   long long totalCost(vector<int>& costs, int k, int candidates) {
//         long long ans=0, i, j, end, start, n;
        
//         n=costs.size();
        
//         priority_queue<int, vector<int>, greater<int>> s, e;
        
//         for(i=0; i<candidates; i++)
//         {
//             s.push(costs[i]);
//         }
        
//         for(i=n-1; i>=candidates && i>=n-candidates; i--)
//         {
//             e.push(costs[i]);
//         }
        
//         start=candidates;
//         end=n-candidates-1;
        
//         while(k>0)
//         {
//             if(s.empty()==false && e.empty()==false){
//             if(s.top()<=e.top())
//             {
//                 ans=ans+s.top();
//                 s.pop();
                
//                 if(start<=end){
//                     s.push(costs[start]);
//                     start++;
//                 }
//             }else{
//                 ans=ans+e.top();
//                 e.pop();
                
//                 if(start<=end){
//                     e.push(costs[end]);
//                     end--;
//                 }
//             }
//             }else if(s.empty()==false){
//                 ans=ans+s.top();
//                 s.pop();
//             }else if(e.empty()==false){
//                 ans=ans+e.top();
//                 e.pop();
//             }
            
//             k--;
//         }
        
//         return ans;
        
        
        
        
//     }
    long long totalCost(vector<int>& costs, int k, int candidates) {
    
    long long ans = 0;   
    int n = costs.size();
    priority_queue<int,vector<int>,greater<int>>pq1,pq2;
    for(int i = 0; i<candidates; i++){
        pq1.push(costs[i]);  
    }
    for(int i = n-1; i>=candidates&&i>=n-candidates; i--){
     pq2.push(costs[i]);
    }
    int l = candidates,r = n-candidates-1;
   while(k--){
       if(!pq1.empty() && !pq2.empty())
       {
          if(pq1.top()<= pq2.top())
          {
              ans += pq1.top();
              pq1.pop();
             
              if(l<=r){
                  pq1.push(costs[l]); 
                  l++;
              }

          }
          else
          {
               ans += pq2.top();
              pq2.pop();

              if(l<=r){
                  pq2.push(costs[r]);  
                  r--;
              }
          }
       }
      else if(!pq1.empty()){
          ans += pq1.top();
          pq1.pop(); 
      }
      else if(!pq2.empty()){
          ans += pq2.top();
          pq2.pop();
      }
    
   }
   return ans;
   
    }

};