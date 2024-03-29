class Solution {
public:
    int pathSum(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& dp)
    {
        if(row==0&&col==0)
            return grid[0][0];
        if(dp[row][col]!=-1)
            return dp[row][col];
        int up=1e8;
        if(row-1>=0)
            up=grid[row][col]+pathSum(row-1,col,grid,dp);
        int left=1e8;
        if(col-1>=0)
            left=grid[row][col]+pathSum(row,col-1,grid,dp);
        return dp[row][col]=min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return pathSum(n-1,m-1,grid,dp);
    }
};