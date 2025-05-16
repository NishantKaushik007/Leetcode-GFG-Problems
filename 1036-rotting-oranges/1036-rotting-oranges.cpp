class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),fresh=0,maxTime=0;
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({0,{i,j}});
                }
                if(grid[i][j]==1)
                fresh++;
            }
        }
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty())
        {
            int row=q.front().second.first;
            int col=q.front().second.second;
            int time=q.front().first;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=delrow[i]+row;
                int ncol=delcol[i]+col;
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&grid[nrow][ncol]==1)
                {
                    q.push({time+1,{nrow,ncol}});
                    fresh--;
                    grid[nrow][ncol]=2;
                }
            }
            maxTime=max(maxTime,time);
        }
        if(fresh==0)
        return maxTime;
        return -1;
    }
};