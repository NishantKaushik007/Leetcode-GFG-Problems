class Solution {
public:
    int dfs(int r,int c,vector<vector<int>>& grid)
    {
        if(r<0||r>=grid.size()||c<0||c>=grid[0].size()||grid[r][c]==0)
            return 0;
        int maxGold=0,originVal=grid[r][c];
        grid[r][c]=0;
        int delrow[4]={1,0,-1,0};
        int delcol[4]={0,1,0,-1};
        for(int i=0;i<4;i++)
        {
            int nrow=delrow[i]+r;
            int ncol=delcol[i]+c;
            maxGold=max(maxGold,dfs(nrow,ncol,grid));
        }
        grid[r][c]=originVal;
        return originVal+maxGold;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),maxi=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!=0)
                {
                    maxi=max(maxi,dfs(i,j,grid));
                }
            }
        }
        return maxi;
    }
};