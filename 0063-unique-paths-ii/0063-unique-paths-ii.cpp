class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp)
    {
        if(i==0&&j==0)
        {
            if(obstacleGrid[0][0]==1)
            return 0;
            else
                return 1;
        }
        if(i<0||j<0)
            return 0;
        if(obstacleGrid[i][j]==1)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int up=solve(i-1,j,obstacleGrid,dp);
        int left=solve(i,j-1,obstacleGrid,dp);
        return dp[i][j]=up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size(),m=obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,obstacleGrid,dp);
    }
};