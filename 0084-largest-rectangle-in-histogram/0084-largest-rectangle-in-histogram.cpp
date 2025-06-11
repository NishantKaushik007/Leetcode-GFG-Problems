class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int largestRectangle=0,n=heights.size();
        stack<int>st;
        vector<int>nse(n),pse(n);
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&heights[st.top()]>=heights[i])
            st.pop();
            pse[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        while(!st.empty())
        st.pop();
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&heights[st.top()]>=heights[i])
            st.pop();
            nse[i]=st.empty()?n:st.top();
            st.push(i);
        }
        for(int i=0;i<n;i++)
        {
            largestRectangle=max(largestRectangle,(nse[i]-pse[i]-1)*heights[i]);
        }
        return largestRectangle;
    }
};