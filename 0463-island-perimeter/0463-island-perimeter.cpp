class Solution {
public:
    int delRow[4]={1,0,-1,0};
    int delCol[4]={0,1,0,-1};
    int dfs(int sr,int sc,vector<vector<int>>& grid,vector<vector<int>>& vis,int& count)
    {
        vis[sr][sc]=1;
        for(int i=0;i<4;i++)
        {
            int nrow=sr+delRow[i];
            int ncol=sc+delCol[i];
            if(nrow<grid.size()&&nrow>=0&&ncol>=0&&ncol<grid[0].size()&&!vis[nrow][ncol]&&grid[nrow][ncol]==1)
            {
                dfs(nrow,ncol,grid,vis,count);
            }
            else if(nrow>=grid.size()||nrow<0&&ncol<0||ncol>=grid[0].size()||grid[nrow][ncol]==0)
                count++;
        }
        return count;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1&&!vis[i][j])
                {
                    int count=0;
                    return dfs(i,j,grid,vis,count);
                }
            }
        }
        return -1;
    }
};