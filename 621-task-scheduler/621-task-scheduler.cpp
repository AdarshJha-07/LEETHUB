class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        unordered_map<char,int>mp;
        int count = 0;
        for(auto e : tasks)
        {
            mp[e]++;
            count = max(count, mp[e]);
        }
        
        int ans = (count-1)*(n+1);
        for(auto e : mp) if(e.second == count) ans++;
        return max((int)tasks.size(), ans);
//         if(n==0) return tasks.size();
        
//         unordered_map<int ,int>mp;
//           int maxi = INT_MIN;
//         for( int i = 0 ; i<tasks.size() ;i++){
//             mp[tasks[i] - 'A']++;
            
//             maxi = max( maxi,mp[tasks[i] - 'A'] );
//         }

        
//       //  sort(mp.begin(), mp.end(), greater<int>() );
      
       
//         int ans=maxi + n*(mp[0] - 1);
        
//         for (auto it: mp)
//         {
//             if( it.second == maxi )ans++;
//         }
        
//         return max((int)tasks.size(), ans);
        // int z = n;
//        for( int i=1 ;i<27 ; i++){
//            if(mp[i]>0){
//               if(i==3)cout<<z<<endl;
//            if(z and  mp[i] == maxi-1){
//                z--;   
//            }
//            else if(z and mp[i] == maxi){
//                ans ++;
//                z--;
//            }
//          else if(z and mp[i] < maxi-1){
          
//                z++;
//            }
//            else if(z==0) {
//                maxi = mp[i];
//                ans += maxi + n*(maxi - 1);
//                z=n;
//            }
//        }
          
       
       
     //   return ans;
    }
};