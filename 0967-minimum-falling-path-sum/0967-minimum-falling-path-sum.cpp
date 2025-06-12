class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int mini=1e9,n=matrix.size(),m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<m;i++)
        dp[0][i]=matrix[0][i];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int dl=1e9;
                if(j>0)
                dl=matrix[i][j]+dp[i-1][j-1];
                int d=matrix[i][j]+dp[i-1][j];
                int dr=1e9;
                if(j+1<m)
                dr=matrix[i][j]+dp[i-1][j+1];
                dp[i][j]=mini=min(dl,min(d,dr));
            }
        }
        for(int i=0;i<m;i++)
        mini=min(mini,dp[m-1][i]);
        return mini;
    }
};