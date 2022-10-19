class Solution {
  
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
      unordered_map<string,int>ump;
        for(int i=0;i<words.size();i++){
            ump[words[i]]++;
        }
        priority_queue<pair<int,string>>pq;
        for(auto it:ump){
            pq.push({it.second,it.first});
        }
        vector<string>ans;
        int prev=0;int cnt=0;
        while(cnt<k){
          //  ans.push_back(pq.top().second);
           
            int u=pq.top().first;
            vector<string>st;
             int x=0;
          //  cout<<pq.top().second<<endl;
              while(!pq.empty()&&pq.top().first==u){
                  st.push_back(pq.top().second);
                  
                 pq.pop();
                  cnt++;
                  x++;
              }
            sort(st.begin(),st.end());
            // cout<<x<<" "<<st[0]<<endl;
            if(st.size()+ans.size()>k)
            ans.insert(ans.end(),st.begin(),st.begin()+(k-ans.size()));
            else ans.insert(ans.end(),st.begin(),st.end());
                if(ans.size()==k)break;
        }
        return ans;
    }
};