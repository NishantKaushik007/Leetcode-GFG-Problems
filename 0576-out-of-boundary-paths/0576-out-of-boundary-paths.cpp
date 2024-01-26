class Solution {
public:
    int mod=1e9+7;
    int delRow[4]={-1,0,+1,0};
    int delCol[4]={0,+1,0,-1};
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(50,vector<vector<int>>(50,vector<int>(51,0)));
        for(int k=1;k<=maxMove;k++)
        {
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    for(int d=0;d<4;d++)
                    {
                        int nrow=i+delRow[d];
                        int ncol=j+delCol[d];
                        if(nrow<0||nrow>=m||ncol<0||ncol>=n)
                            dp[i][j][k]=(dp[i][j][k]+1)%mod;
                        else
                            dp[i][j][k]=(dp[i][j][k]+dp[nrow][ncol][k-1])%mod;
                    }
                }
            }
        }
        return dp[startRow][startColumn][maxMove];
    }
};