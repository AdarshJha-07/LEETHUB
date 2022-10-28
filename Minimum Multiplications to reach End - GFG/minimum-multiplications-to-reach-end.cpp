//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
typedef pair<int,int>pii;
class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        int n = arr.size();
    
       int mod = 100000;
       vector<int>dist(mod,INT_MAX);
    //   queue<int>q;
       queue<pii>q;
       q.push({0,start});
       dist[start%mod] = 0;
       int steps = 0;
       while(!q.empty())
       {
         
               int u = q.front().second;
               int w = q.front().first;
            //   if( u == end) return w;
               q.pop();
               for(auto it: arr){
                  int v = (1LL*it*u)%mod;
                  
                  if(dist[v] > w + 1)
                { 
                    dist[v] = w+1;
                    if(v == end) return dist[v];
                    q.push({w+1,v});
                }
               }
               
       }
       
      return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends