class Solution {
public:
    int delRow[4]={1,0,-1,0};
    int delCol[4]={0,1,0,-1};
    int bfs(int sr,int sc,vector<vector<int>>& grid,vector<vector<int>>& vis)
    {
        int count=0;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        vis[sr][sc]=1;
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=row+delRow[i];
                int ncol=col+delCol[i];
                if(nrow<grid.size()&&nrow>=0&&ncol>=0&&ncol<grid[0].size()&&!vis[nrow][ncol]&&grid[nrow][ncol]==1)
                {
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
                else if(nrow>=grid.size()||nrow<0&&ncol<0||ncol>=grid[0].size()||grid[nrow][ncol]==0)
                    count++;
            }
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
                    return bfs(i,j,grid,vis);
                }
            }
        }
        return -1;
    }
};