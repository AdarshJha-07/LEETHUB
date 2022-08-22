class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
     
      int endRow = matrix.size()-1;
      int startRow = 0;
      
        int endCol = matrix[0].size()-1;
        int startCol = 0;
        
        int dir = 0 ;
        vector<int>ans;
        while(startRow<=endRow && startCol<=endCol ){
            
            switch(dir)
            {
                case 0: {
                    for( int j=startCol ;j<=endCol ;j++ ){  //up
                        ans.push_back(matrix[startRow][j]);
                    }
                    startRow++;
                    
                    break;
                } 
                    
                case 1 :{
                    for( int i = startRow ; i<=endRow ;i++){     //right
                        ans.push_back(matrix[i][endCol]);
                    }
                    endCol--;
                    break;
                    
                }
                case 2 :{
                    for( int j = endCol ;j>=startCol ;j-- ){   ///down
                     ans.push_back(matrix[endRow][j]);
                    }
                    endRow--;
                    break;
                    
                }
                case 3 :{
                    
                    for( int i = endRow ;i>=startRow ;i--){
                        ans.push_back(matrix[i][startCol]);
                    }
                    startCol++;
                    break;
                }
            }           
            
            
            dir = (1+dir)%4;
            
        }
        
    return ans;
     
    }
};