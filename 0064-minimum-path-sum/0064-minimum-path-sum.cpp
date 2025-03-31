class Solution {
public:
    int pathSum(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp)
    {
        if(i==0&&j==0)
        return grid[i][j];
        if(i<0||j<0)
        return 1e8;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int up=grid[i][j]+pathSum(i-1,j,grid,dp);
        int left=grid[i][j]+pathSum(i,j-1,grid,dp);
        return dp[i][j]=min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return pathSum(n-1,m-1,grid,dp);
    }
};