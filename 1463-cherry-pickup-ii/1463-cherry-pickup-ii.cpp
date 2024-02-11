class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<int>>prev(grid[0].size(),vector<int>(grid[0].size(),-1));
        vector<vector<int>>curr(grid[0].size(),vector<int>(grid[0].size(),-1));
        for(int j1=0;j1<grid[0].size();j1++)
        {
            for(int j2=0;j2<grid[0].size();j2++)
            {
                if(j1==j2)
                prev[j1][j2]=grid[grid.size()-1][j1];
                else
                prev[j1][j2]=grid[grid.size()-1][j1]+grid[grid.size()-1][j2];
            }
        }
        for(int i=grid.size()-2;i>=0;i--)
        {
            for(int j1=0;j1<grid[0].size();j1++)
            {
                for(int j2=0;j2<grid[0].size();j2++)
                {
                    int maxi=-1e8;
                    for(int dg1=-1;dg1<=1;dg1++)
                    {
                        for(int dg2=-1;dg2<=1;dg2++)
                        {
                            int val=0;
                            if(j1==j2)
                            val=grid[i][j1];
                            else
                            val=grid[i][j1]+grid[i][j2];
                            if(j1+dg1>=0&&j1+dg1<=grid[0].size()-1&&j2+dg2>=0&&j2+dg2<=grid[0].size()-1)
                            val+=prev[j1+dg1][j2+dg2];
                            else
                            val+=-1e8;
                            maxi=max(maxi,val);
                        }
                    }
                    curr[j1][j2]=maxi;
                }
            }
            prev=curr;
        }
        return prev[0][grid[0].size()-1];
    }
};