class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& grid,int delrow[],int delcol[])
    {
        vis[row][col]=1;
        for(int i=0;i<4;i++)
        {
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0&&nrow<grid.size()&&ncol>=0&&ncol<grid[0].size()&&!vis[nrow][ncol]&&grid[nrow][ncol]=='1')
                dfs(nrow,ncol,vis,grid,delrow,delcol);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        int count=0;
        int delrow[]={1,0,-1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1'&&!vis[i][j])
                {
                    count++;
                    dfs(i,j,vis,grid,delrow,delcol);
                }
                    
            }
        }
        return count;
    }
};