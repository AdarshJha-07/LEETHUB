class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
     
        vector<int>next(heights.size(),0);
        vector<int>ans(heights.size(),0);
        stack<int>st;
        for( int i = 0; i<heights.size(); i++)
        {
            
            while(!st.empty()&&heights[i]>heights[st.top()])
            {
                // next[st.top()] = i;
                ans[st.top()]++;
                st.pop();
            }            
            if(st.size())ans[st.top()]++;
            
            st.push(i);
            
        }
      
        return ans; 
    }
};