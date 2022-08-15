class Solution {
    bool static cmp( const pair<int,int>&a , const pair<int,int>&b ){
        
        return a.first<b.first;
    }
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
       unordered_map<int,int>ump;
        int cnt=0;
        for( auto it: unordered_set<int>(nums.begin(),nums.end()))
        {
            cnt=0;
            for(int i=0; i<32 ;i++){
                if(it &(1<<i)){
                    cnt++;
                }
            }
            ump[cnt]++;
        }

     
        
        long long ans=0;
       for( int i=1; i<32; i++){
         for( int j=1; j<32; j++){
             if( i+j>=k && ump[i]&&ump[j]){
                // cout<<i<<" "<<j<<endl;
                 ans+=1LL*ump[i]*ump[j];
             }
         }  
       }
        
    return ans;
    }
};