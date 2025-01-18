class Solution {
public:
    int pathSum(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp)
    {
        if(i==0&&j==0)
        return grid[0][0];
        if(i<0||j<0)
        return 1e8;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int up=1e9;
        if(i-1>=0)
        up=grid[i][j]+pathSum(i-1,j,grid,dp);
        int left=1e9;
        if(j-1>=0)
        left=grid[i][j]+pathSum(i,j-1,grid,dp);
        return dp[i][j]=min(left,up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0&&j==0)
                dp[i][j]=grid[i][i];
                else{
                    int up=1e8;
                    if(i-1>=0)
                    up=grid[i][j]+dp[i-1][j];
                    int left=1e8;
                    if(j-1>=0)
                    left=grid[i][j]+dp[i][j-1];
                    dp[i][j]=min(left,up);
                }
            }
        }
        return dp[n-1][m-1];
    }
};