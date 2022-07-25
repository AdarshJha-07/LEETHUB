class Solution {
    int n;
    string cntsy(int i,string s){
        if(i==n){
        
            return s;
        }
        unordered_map<int,int>ump;
        string res="";
        if(i==3)cout<<s<<endl;
      for(int j=0;j<(int)s.size();j++){
        //  if(i==3)cout<<j<<endl;
       int c=s[j]-'0';
          int cnt=0;
          while(s[j]-'0'==c){
              cnt++;
              j++;
          }
          j--;
       
          res+=to_string(cnt)+to_string(c);
          
      }


        return cntsy(i+1,res);
    }
public:
    string countAndSay(int n) {
         this->n=n;  
        return cntsy(1,"1");
    }
};