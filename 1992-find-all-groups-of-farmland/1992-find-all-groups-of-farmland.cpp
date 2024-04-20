class Solution {
public:
    int delrow[4]={1,0,-1,0};
    int delcol[4]={0,1,0,-1};
    pair<int,int> dfs(int row,int col,vector<vector<int>>& vis,vector<vector<int>>& land,int& maxrow,int& maxcol)
    {
        vis[row][col]=1;
        maxrow=max(maxrow,row);
        maxcol=max(maxcol,col);
        for(int i=0;i<4;i++)
        {
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow<land.size()&&nrow>=0&&ncol>=0&&ncol<land[0].size()&&!vis[nrow][ncol]&&land[nrow][ncol]==1)
            {
                dfs(nrow,ncol,vis,land,maxrow,maxcol);
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
                    coord.push_back(i);
                    coord.push_back(j);
                    int maxrow=0,maxcol=0;
                    pair<int,int>x=dfs(i,j,vis,land,maxrow,maxcol);
                    coord.push_back(x.first);
                    coord.push_back(x.second);
                    ans.push_back(coord);
                }
            }
        }
        return ans;
    }
};