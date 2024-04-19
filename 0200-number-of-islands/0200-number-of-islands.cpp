class Solution {
public:
    int delrow[4]={1,0,-1,0};
    int delcol[4]={0,1,0,-1};
    void dfs(int r,int c,vector<vector<int>>& vis,vector<vector<char>>& grid)
    {
        vis[r][c]=1;
        for(int i=0;i<4;i++)
        {
            int nrow=delrow[i]+r;
            int ncol=delcol[i]+c;
            if(nrow<grid.size()&&nrow>=0&&ncol<grid[0].size()&&ncol>=0&&grid[nrow][ncol]=='1'&&!vis[nrow][ncol])
            {
                dfs(nrow,ncol,vis,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1'&&!vis[i][j])
                {
                    dfs(i,j,vis,grid);
                    count++;
                }
            }
        }
        return count;
    }
};