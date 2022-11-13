class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        double k = celsius + 273.15;
        vector<double>ans;
        ans.push_back(k);
        // cout<<k<<endl;
        // ans.push_back(k);
        double  f = celsius*1.80 + 32.00;
        ans.push_back(f);
        return ans;
    }
};