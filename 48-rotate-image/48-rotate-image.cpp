class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        for(int i=0;i<n;i++){
            int j=i;
            for(;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
      for(int i=0;i<n;i++){
          int l=0,h=n-1;
          while(l<h){
              swap(matrix[i][l],matrix[i][h]);
              l++;
              h--;
          }
      }
        
        
    }
};