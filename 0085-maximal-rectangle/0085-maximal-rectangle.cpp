class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size(),largest=0;
        vector<int>pse(n),nse(n),width(n);
        stack<int>st;
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
        width[i]=(nse[i]-pse[i])-1;
        for(int i=0;i<n;i++)
        largest=max(largest,heights[i]*width[i]);
        return largest;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size(),maxRectangle=0;
        vector<vector<int>>prefixMat(n,vector<int>(m,-1));
        for(int i=0;i<m;i++)
        prefixMat[0][i]=matrix[0][i]-'0';
        for(int j=0;j<m;j++)
        {
            for(int i=1;i<n;i++)
            {
                if(matrix[i][j]=='0')
                prefixMat[i][j]=0;
                else
                prefixMat[i][j]=prefixMat[i-1][j]+1;
            }
        }
        for(int i=0;i<n;i++)
        {
            maxRectangle=max(maxRectangle,largestRectangleArea(prefixMat[i]));
        }
        return maxRectangle;
    }
};