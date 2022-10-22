class Solution {
public:
    string minWindow(string s, string t) {
  
   unordered_map<char,int>ump;
        for(int i=0;i<t.size();i++){
            ump[t[i]]++;
        }
        int low=0,high=0,count=0;
        int min_length= INT_MAX,start=low;
        while(high<s.size()){
            
            if(ump[s[high]]>0)count++;
            ump[s[high]]--;
            if(count==t.size()){
                while(low<high&&ump[s[low]]<0)ump[s[low++]]++;
                if(min_length>(high-low+1))min_length=(high-(start=low)+1);
        // ump[s[low++]]++;
        //         count--;
            }
            high++;
        }
        return min_length==INT_MAX?"":s.substr(start,min_length);
    }
};