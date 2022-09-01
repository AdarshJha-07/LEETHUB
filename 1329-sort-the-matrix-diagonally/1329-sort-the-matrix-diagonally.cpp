class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        int z = -1;
        
        int n = mat.size() ,m = mat[0].size();
        for( int i = mat.size()-1; i>=0 ; i--)
        {
          int z = i;
            vector<int>temp;
           for( int k = 0; k<m&&z<n ;k++)
           {
               temp.push_back( mat[z++][k]);
           }
          
            sort(temp.begin() , temp.end());
            z = i;
             for( int k = 0; k<temp.size() ;k++)
           {
                mat[z++][k] = temp[k];
           }
         
        }
        
     for( int j = 1; j<m ;j++){
         
         int z = j;
         vector<int>temp;
         for( int k =0; k<n&&z<m; k++){
             
             temp.push_back(mat[k][z++]);
         }
         sort(temp.begin() , temp.end());
         
         z = j;
          for( int k =0; k<temp.size(); k++){
             
            mat[k][z++] = temp[k];
         }
         
     }
        
        
        return mat;
        
    }
};