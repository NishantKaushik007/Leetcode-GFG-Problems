class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>>ans(grid.size()-2,vector<int>(grid[0].size()-2,0));
        for(int i=0;i<grid.size()-2;i++)
        {
            for(int j=0;j<grid[0].size()-2;j++)
            {
                for(int k=0;k<3;k++)
                {
                    for(int l=0;l<3;l++)
                    {
                        ans[i][j]=max(ans[i][j],grid[i+k][j+l]);
                    }
                }
            }
        }
        return ans;
    }
};