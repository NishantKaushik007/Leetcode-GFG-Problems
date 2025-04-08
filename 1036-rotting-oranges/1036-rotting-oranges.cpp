class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>>q;
        int count=0,maxTime=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({0,{i,j}});
                }
                if(grid[i][j]==1)
                count++;
            }
        }
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty())
        {
            int time=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=delrow[i]+row;
                int ncol=delcol[i]+col;
                if(nrow>=0&&nrow<grid.size()&&ncol>=0&&ncol<grid[0].size()&&grid[nrow][ncol]==1)
                {
                    q.push({time+1,{nrow,ncol}});
                    grid[nrow][ncol]=2;
                    count--;
                }
            }
            maxTime=max(maxTime,time);
        }
        if(count==0)
        return maxTime;
        return -1;
    }
};