class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size(),mini=1e8;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<m;i++)
        dp[n-1][i]=matrix[n-1][i];
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<m;j++)
            {
                int up=matrix[i][j]+dp[i+1][j];
                int left=1e8;
                if(j-1>=0)
                left=matrix[i][j]+dp[i+1][j-1];
                int right=1e8;
                if(j+1<matrix[0].size())
                right=matrix[i][j]+dp[i+1][j+1];
                dp[i][j]=min(left,min(right,up));
            }
        }
        for(int i=0;i<m;i++)
        {
            mini=min(mini,dp[0][i]);
        }
        return mini;
    }
};