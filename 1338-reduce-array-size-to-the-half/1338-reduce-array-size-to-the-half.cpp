class Solution {
    bool static cmp(const pair<int,int>&a,const pair<int,int>&b){
        return a.first>b.first;
    }
public:
    
    int minSetSize(vector<int>& arr) {
        
        unordered_map<int,int>ump;
        
        for( int i=0; i<arr.size(); i++){
            ump[arr[i]]++;
        }
        vector<pair<int,int>>v;
        
        for(auto it: ump){
            
            v.push_back({it.second ,it.first});
            
        }
        sort(v.begin(),v.end(),cmp);
        
        int sum = 0 ,cnt = 0;
        for ( int i=0; i<v.size(); i++){
            if(sum + v[i].first >=arr.size()/2){
                return cnt+1;
            }
            else{
                sum += v[i].first;
                cnt++;
            }
            
        }
        return cnt;
    }
};