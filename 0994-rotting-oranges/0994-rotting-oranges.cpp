class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),time=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j]&&grid[i][j]==2)
                {
                    vis[i][j]=1;
                    q.push({i,{j,time}});
                }
            }
        }
        int delRow[]={1,0,-1,0};
        int delCol[]={0,1,0,-1};
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second.first;
            time=q.front().second.second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=row+delRow[i];
                int ncol=col+delCol[i];
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&!vis[nrow][ncol]&&grid[nrow][ncol]==1)
                {
                    vis[nrow][ncol]=1;
                    grid[nrow][ncol]=2;
                    q.push({nrow,{ncol,time+1}});
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                    return -1;
            }
        }
        return time;
    }
};