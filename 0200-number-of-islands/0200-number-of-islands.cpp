class Solution {
public:
    int delrow[4]={1,0,-1,0};
    int delcol[4]={0,1,0,-1};
    void bfs(int r,int c,vector<vector<int>>& vis,vector<vector<char>>& grid)
    {
        queue<pair<int,int>>q;
        q.push({r,c});
        vis[r][c]=1;
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=delrow[i]+row;
                int ncol=delcol[i]+col;
                if(nrow<grid.size()&&nrow>=0&&ncol<grid[0].size()&&ncol>=0&&grid[nrow][ncol]=='1'&&!vis[nrow][ncol])
                {
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
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
                    bfs(i,j,vis,grid);
                    count++;
                }
            }
        }
        return count;
    }
};