class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<int>prev(obstacleGrid[0].size(),0),curr(obstacleGrid[0].size(),0);
        for(int i=0;i<obstacleGrid.size();i++)
        {
            for(int j=0;j<obstacleGrid[0].size();j++)
            {
                if(obstacleGrid[i][j]==1)
                curr[j]=0;
                else if(i==0&&j==0)
                curr[j]=1;
                else{
                    int up=0;
                    if(i>0)
                    up=prev[j];
                    int left=0;
                    if(j>0)
                    left=curr[j-1];
                    curr[j]=up+left;
                }
                prev=curr;
            }
        }
        return prev[obstacleGrid[0].size()-1];
    }
};