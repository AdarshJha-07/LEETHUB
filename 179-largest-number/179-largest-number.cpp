class Solution {
    
    
public:
    static	bool cmp(const string &a, const string &b)
    {
	   return a+b > b+a;
	}
    string largestNumber(vector<int> arr) {
        vector<string>a(arr.size());
        
        for(int i =0; i<arr.size(); i++){
            a[i] = to_string(arr[i]);
        }
      sort(a.begin() ,a.end() ,cmp);
	  
	  string ans ;
	  
	  for( auto it: a) ans += it;
	  while(ans[0]=='0')
          ans.erase(ans.begin());
        
        if(ans == "")return "0";
        return ans;
    }
};