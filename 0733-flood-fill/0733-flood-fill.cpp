class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size(),m=image[0].size();
        vector<vector<int>>ans=image,vis(n,vector<int>(m,0));
        int delRow[]={1,0,-1,0};
        int delCol[]={0,1,0,-1};
        queue<pair<int,int>>q;
        q.push({sr,sc});
        vis[sr][sc]=1;
        ans[sr][sc]=color;
        int orignal=image[sr][sc];
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=row+delRow[i];
                int ncol=col+delCol[i];
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&!vis[nrow][ncol]&&image[nrow][ncol]==orignal)
                {
                    vis[nrow][ncol]=1;
                    ans[nrow][ncol]=color;
                    q.push({nrow,ncol});
                }
            }
        }
        return ans;
    }
};