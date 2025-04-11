class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        dist[0][0]=0;
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};
        while(!pq.empty())
        {
            int effort=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            if(r==n-1&&c==m-1)
            return effort;
            for(int i=0;i<4;i++)
            {
                int nrow=delrow[i]+r;
                int ncol=delcol[i]+c;
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m)
                {
                    int neffort=max(effort,abs(heights[nrow][ncol]-heights[r][c]));
                    if(neffort<dist[nrow][ncol])
                    {
                        pq.push({neffort,{nrow,ncol}});
                        dist[nrow][ncol]=neffort;
                    }
                }
            }
        }
        return 0;
    }
};