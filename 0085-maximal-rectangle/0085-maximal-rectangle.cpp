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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size(),maxRectangle=0;
        vector<vector<int>>mat(n,vector<int>(m,0));
        for(int i=0;i<m;i++)
        {
            if(matrix[0][i]=='1')
            mat[0][i]=1;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='1')
                {
                    mat[i][j]=mat[i-1][j]+1;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            maxRectangle=max(maxRectangle,largestRectangleArea(mat[i]));
        }
        return maxRectangle;
    }
};