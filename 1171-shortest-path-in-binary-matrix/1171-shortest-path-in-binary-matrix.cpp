class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        if(grid[0][0]==1||grid[n-1][n-1]==1)
        return -1;
        queue<pair<int,pair<int,int>>>q;
        if(grid[0][0]==0)
        {
            q.push({1,{0,0}});
            dist[0][0]=1;
        }
        int delrow[8]={1,1,0,-1,-1,-1,0,1};
        int delcol[8]={0,1,1,1,0,-1,-1,-1};
        while(!q.empty())
        {
            int d=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();
            if(r==n-1&&c==n-1)
            {
                return d;
            }
            for(int i=0;i<8;i++)
            {
                int nrow=r+delrow[i];
                int ncol=c+delcol[i];
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<n&&dist[nrow][ncol]>d+1&&grid[nrow][ncol]==0)
                {
                    q.push({d+1,{nrow,ncol}});
                    dist[nrow][ncol]=d+1;
                }
            }
        }
        return -1;
    }
};