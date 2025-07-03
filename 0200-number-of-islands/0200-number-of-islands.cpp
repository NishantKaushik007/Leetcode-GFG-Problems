class Solution {
    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,1,0,-1};
public:
    void dfs(int r,int c,vector<vector<char>>& grid,vector<vector<int>>& vis)
    {
        vis[r][c]=1;
        for(int i=0;i<4;i++)
        {
            int nrow=delrow[i]+r;
            int ncol=delcol[i]+c;
            if(nrow>=0&&nrow<grid.size()&&ncol>=0&&ncol<grid[0].size()&&!vis[nrow][ncol]&&grid[nrow][ncol]=='1')
            {
                dfs(nrow,ncol,grid,vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size(),count=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j]&&grid[i][j]=='1')
                {
                    count++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return count;
    }
};