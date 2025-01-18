class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size(),mini=1e8;
        vector<int>ahead(m,-1);
        for(int i=0;i<m;i++)
        ahead[i]=matrix[n-1][i];
        for(int i=n-2;i>=0;i--)
        {
            vector<int>curr(m,-1);
            for(int j=0;j<m;j++)
            {
                int up=matrix[i][j]+ahead[j];
                int left=1e8;
                if(j-1>=0)
                left=matrix[i][j]+ahead[j-1];
                int right=1e8;
                if(j+1<matrix[0].size())
                right=matrix[i][j]+ahead[j+1];
                curr[j]=min(left,min(right,up));
            }
            ahead=curr;
        }
        for(int i=0;i<m;i++)
        {
            mini=min(mini,ahead[i]);
        }
        return mini;
    }
};