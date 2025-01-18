class Solution {
public:
    int paths(int i,int j,vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp)
    {
        if(obstacleGrid[i][j]==1)
        return 0;
        if(i==0&&j==0)
        return 1;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int up=0;
        if(i-1>=0)
        up=paths(i-1,j,obstacleGrid,dp);
        int left=0;
        if(j-1>=0)
        left=paths(i,j-1,obstacleGrid,dp);
        return dp[i][j]=left+up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size(),m=obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return paths(n-1,m-1,obstacleGrid,dp);
    }
};