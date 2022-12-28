class Solution {
public:
    int maximumBags(vector<int>& cap, vector<int>& rocks, int adR) {
        int n = cap.size();
        vector<int>diff(n,0);
        int cnt = 0;
        for(int i = 0; i<n; i++){
            diff[i] = cap[i]-rocks[i];
            if(diff[i] == 0){
                cnt++;
            }
        }
        sort(diff.begin(),diff.end());
        for(int i = 0; i<n; i++){
            if(diff[i] == 0)continue;
            else if(adR >= diff[i]){
                cnt++;
                adR -= diff[i];
            }
            else break;    
        }
    return cnt;
    }
};