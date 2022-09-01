class Solution {
public:
    
    int solve(vector<int> &arr,int k){
        
        
        set<int> s;
        s.insert(0);
        
        
        int sum = 0;
        
        int ans = INT_MIN;
        
        for(int i = 0; i < arr.size(); i++){
            
            sum += arr[i];
            

            auto it = s.lower_bound(sum - k);
            
            if(it != s.end()){
                ans = max(ans,sum-*it);
            }
                
            
            s.insert(sum);
        
        }
        
        return ans;
        
        
//         int sum = 0;
        
//         int l = 0;
        
//         int ans = 0;

        
        
//         for(int r = 0; r < arr.size(); r++){
//             sum += arr[r];
//             while(sum > k){
//                 sum -= arr[l];
//                 l++;
//             }
//             ans = max(ans,sum);
//         }
        
//         return ans;
        
    }
    
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        
        
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                matrix[i][j] += matrix[i-1][j];
            }
        }
        
        int ans = INT_MIN;
        
        vector<int> arr;
        
        
        for(int i = 0; i < matrix.size(); i++){
            for(int j = i; j < matrix.size(); j++){
                
                vector<int> arr;
                
                arr = matrix[j];
                
                if(i > 0){
                    for(int k = 0; k < matrix[i].size(); k++){
                        arr[k] -= matrix[i-1][k];
                    }
                }
                
                ans = max(ans,solve(arr,k));
            }
        }
        
        
        
        return ans;
    }
};