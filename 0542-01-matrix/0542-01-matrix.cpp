class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0)),dis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        while(!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int steps=q.front().second;
            q.pop();
            dis[row][col]=steps;
            for(int i=0;i<4;i++)
            {
                int nRow=row+delRow[i];
                int nCol=col+delCol[i];
                if(nRow>=0&&nRow<n&&nCol>=0&&nCol<m&&vis[nRow][nCol]==0)
                {
                    vis[nRow][nCol]=1;
                    q.push({{nRow,nCol},steps+1});
                }
            }
        }
        return dis;
    }
};