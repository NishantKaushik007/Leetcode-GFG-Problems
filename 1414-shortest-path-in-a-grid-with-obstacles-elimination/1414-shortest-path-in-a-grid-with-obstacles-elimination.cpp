class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<vector<int>>>vis(n,vector<vector<int>>(m,vector<int>(k+1,0)));
        queue<tuple<int,int,int,int>>q;
        q.push({0,0,0,0});
        vis[0][0][0]=1;
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};
        while(!q.empty())
        {
            auto [steps,row,col,usedK]=q.front();
            q.pop();
            if(row==n-1&&col==m-1)
            return steps;
            for(int i=0;i<4;i++)
            {
                int nrow=delrow[i]+row;
                int ncol=delcol[i]+col;
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m)
                {
                    int newK=usedK+grid[nrow][ncol];
                    if(newK<=k&&!vis[nrow][ncol][newK])
                    {
                        q.push({steps+1,nrow,ncol,newK});
                        vis[nrow][ncol][newK]=1;
                    }
                }
            }
        }
        return -1;
    }
};