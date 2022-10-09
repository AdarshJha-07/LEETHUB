class Solution {
public:
    string robotWithString(string sr) {
        int n = sr.size();
        vector<char>v(n);
        v[n-1] = sr.back();
        for(int i= n-2; i>=0; i--){
            if(sr[i]<v[i+1])v[i]=sr[i];
            else v[i]=v[i+1];
        }
       // for(auto it: v)cout<<it<<" ";
        string t = "",p = "";
        for(int i =0; i<n; i++){
            char c = sr[i];
            
            while(t.size() >0 and v[i] >= t.back()){
                p += t.back();
                t.pop_back();
            }
            t += c;
           // cout<<t<<endl;
        }
        while(t.size()>0)
        {
            p += t.back();
           
            t.pop_back();
        }
        return p;
    }
};