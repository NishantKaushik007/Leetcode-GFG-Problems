class Solution {
public:
    int delrow[4]={1,0,-1,0};
    int delcol[4]={0,1,0,-1};
    pair<int,int> bfs(int row,int col,vector<vector<int>>& vis,vector<vector<int>>& land)
    {
        queue<pair<int,int>>q;
        q.push({row,col});
        vis[row][col]=1;
        int maxrow=row,maxcol=col;
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=r+delrow[i];
                int ncol=c+delcol[i];
                if(nrow<land.size()&&nrow>=0&&ncol>=0&&ncol<land[0].size()&&!vis[nrow][ncol]&&land[nrow][ncol]==1)
                {
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                    maxrow=max(maxrow,nrow);
                    maxcol=max(maxcol,ncol);
                }
            }
        }
        return {maxrow,maxcol};
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n=land.size(),m=land[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0)),ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j]&&land[i][j]==1)
                {
                    vector<int>coord;
                    pair<int,int>x=bfs(i,j,vis,land);
                    coord.push_back(i);
                    coord.push_back(j);
                    coord.push_back(x.first);
                    coord.push_back(x.second);
                    ans.push_back(coord);
                }
            }
        }
        return ans;
    }
};