class Solution {
     int largestRectangleArea(vector<int>& heights) {
     
        stack<int>st;
        vector<int>nextsmall(heights.size());
        for(int i=0;i<heights.size();i++){
            while(!st.empty()&&heights[st.top()]>heights[i]){
                nextsmall[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
         
            nextsmall[st.top()]=heights.size();
            st.pop();
        }
        vector<int>prevsmall(heights.size());
        for(int i=heights.size()-1;i>=0;i--)
        {
            while(!st.empty()&&heights[st.top()]>heights[i]){
                prevsmall[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            prevsmall[st.top()]=-1;
            st.pop();
        }
        
        int maxsum=0;
        for(int i=0;i<heights.size();i++){
            maxsum=max(maxsum,heights[i]*((i-prevsmall[i])+(nextsmall[i]-i)-1));
          
        }
      

        return maxsum;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans=INT_MIN;
        vector<int>temp(matrix[0].size(),0);
        
        for(int i =0 ;i <matrix.size() ;i++){
            for(int j=0; j<matrix[i].size(); j++){
                if(matrix[i][j]=='1')temp[j]++;
                else temp[j]=0;
            }
            
          ans=max(ans,largestRectangleArea(temp));  
            
            
        }
        return ans;
    }
};