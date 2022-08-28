class Solution {
  
public:
    vector<int> answerQueries(vector<int>& a, vector<int>& q) {
        sort(a.begin(), a.end());
        for(int i = 1; i < a.size(); i++){
            a[i] += a[i-1];
        }
        vector<int> res;
        for(int i: q){
            
            int j;
            for(j = 0; j < a.size(); j++){
                if(a[j] > i) break;
            }
            res.push_back(j);
        }
        return res;
    }
};