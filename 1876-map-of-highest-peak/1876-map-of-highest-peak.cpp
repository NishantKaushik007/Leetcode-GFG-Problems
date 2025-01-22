class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        vector<vector<int>>vis(isWater.size(),vector<int>(isWater[0].size(),-1));
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<isWater.size();i++)
        {
            for(int j=0;j<isWater[0].size();j++)
            {
                if(isWater[i][j]==1&&vis[i][j]==-1)
                {
                    q.push({0,{i,j}});
                    vis[i][j]=0;
                }
            }
        }
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};
        while(!q.empty())
        {
            int lvl=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0&&nrow<isWater.size()&&ncol>=0&&ncol<isWater[0].size()&&isWater[nrow][ncol]==0&&vis[nrow][ncol]==-1)
                {
                    q.push({lvl+1,{nrow,ncol}});
                    vis[nrow][ncol]=lvl+1;
                }
            }
        }
        return vis;
    }
};