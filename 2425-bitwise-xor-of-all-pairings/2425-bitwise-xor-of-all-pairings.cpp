class Solution {
    int xorr( vector<int>&a){
        
        int ans = 0;
        for( int i =0;i<a.size(); i++)
            ans ^= a[i];
        
        return ans;
    }
    int xor3( vector<int>&a,vector<int>&b){
        
        int ans = 0;
        for( int i =0;i<a.size(); i++)
            ans ^= a[i];
        for( int i =0;i<b.size(); i++)
            ans ^= b[i];
        
        return ans;
    }
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        if( n1%2 ==0 && n2%2 == 0) return 0;
        
        if(n1%2 == 0) return xorr(nums1);
        
        if( n2 % 2 == 0) return xorr(nums2);
        
        return xor3(nums1 , nums2);
    }
};