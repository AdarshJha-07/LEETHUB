class Solution {
  
public:
    vector<int> answerQueries(vector<int>& a, vector<int>& q) {
        sort(a.begin(), a.end());
     
        vector<int> res;
        for(int i: q){
            int sum = 0;
            int j;
            for(j = 0; j < a.size(); j++){
                if(sum + a[j] > i) break;
                sum += a[j];
            }
            res.push_back(j);
        }
        return res;
    }
};