class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans=image;
        vector<vector<int>>vis(image.size(),vector<int>(image[0].size(),0));
        int delRow[]={1,0,-1,0};
        int delCol[]={0,1,0,-1};
        queue<pair<int,int>>q;
        int px=image[sr][sc];
        q.push({sr,sc});
        vis[sr][sc]=1;
        ans[sr][sc]=color;
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=row+delRow[i];
                int ncol=col+delCol[i];
                if(nrow>=0&&nrow<image.size()&&ncol>=0&&ncol<image[0].size()&&!vis[nrow][ncol]&&image[nrow][ncol]==px)
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