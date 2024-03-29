class Solution {
public:
    void bfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& grid,int delrow[],int delcol[])
    {
        queue<pair<int,int>>q;
        q.push({row,col});
        vis[row][col]=1;
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=r+delrow[i];
                int ncol=c+delcol[i];
                if(nrow>=0&&nrow<grid.size()&&ncol>=0&&ncol<grid[0].size()&&!vis[nrow][ncol]&&grid[nrow][ncol]=='1')
                {
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
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
                    bfs(i,j,vis,grid,delrow,delcol);
                }
                    
            }
        }
        return count;
    }
};