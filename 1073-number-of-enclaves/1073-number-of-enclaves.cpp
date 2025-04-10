class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>& mat,vector<vector<int>>& vis,int delrow[],int delcol[])
    {
        vis[r][c]=1;
        for(int i=0;i<4;i++)
        {
            int nrow=delrow[i]+r;
            int ncol=delcol[i]+c;
            if(nrow>=0&&nrow<mat.size()&&ncol>=0&&ncol<mat[0].size()&&!vis[nrow][ncol]&&mat[nrow][ncol]==1)
            dfs(nrow,ncol,mat,vis,delrow,delcol);
        }
    }
    int numEnclaves(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(),count=0;
        vector<vector<int>>vis(n, vector<int>(m, 0));
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};
        for (int i = 0; i < n; i++) {
            if (mat[i][0] == 1 && !vis[i][0]) dfs(i, 0, mat, vis,delrow,delcol);
            if (mat[i][m-1] == 1 && !vis[i][m-1]) dfs(i, m-1, mat, vis,delrow,delcol);
        }
        for (int i = 0; i < m; i++) {
            if (mat[0][i] == 1 && !vis[0][i]) dfs(0, i, mat, vis,delrow,delcol);
            if (mat[n-1][i] == 1 && !vis[n-1][i]) dfs(n-1, i, mat, vis,delrow,delcol);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1&&!vis[i][j])
                count++;
            }
        }
        return count;
    }
};