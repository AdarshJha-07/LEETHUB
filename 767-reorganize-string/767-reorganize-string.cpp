class Solution {
public:
    string reorganizeString(string str) {
        unordered_map<char,int>arr;
        for(int i=0;i<str.length();i++){
         arr[str[i]]++;   
        }
        priority_queue<pair<int,char>>pq;
         for(auto &it:arr)
             pq.push(make_pair(it.second,it.first));
        string ans;
        pair<int,char>prev={-1,'%'};
         pair<int,char>top1;
        while(!pq.empty())
        {  
            top1=pq.top();
         
         pq.pop();
         ans+=top1.second;
             if(prev.first>0){
             pq.push(prev);
            }
            
          top1.first--;
           // if(top1.first!=0)pq.push({top1.first,top1.second});
         prev=top1;
        }
        
        if(ans.size()!=str.size())return "";
        return ans;
    }
};