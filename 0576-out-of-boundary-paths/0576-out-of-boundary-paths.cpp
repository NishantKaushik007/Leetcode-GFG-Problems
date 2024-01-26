class Solution {
public:
    int mod=1e9+7;
    int delRow[4]={-1,0,+1,0};
    int delCol[4]={0,+1,0,-1};
    int solve(int startRow,int startColumn,int maxMove,int m,int n,vector<vector<vector<int>>> &dp)
    {
        if(startRow<0||startRow>=m||startColumn<0||startColumn>=n)
            return 1;
        if(maxMove<=0)
            return 0;
        if(dp[startRow][startColumn][maxMove]!=-1)
            return dp[startRow][startColumn][maxMove];
        int result=0;
        for(int i=0;i<4;i++)
        {
            int nrow=startRow+delRow[i];
            int ncol=startColumn+delCol[i];
            result=(result+solve(nrow,ncol,maxMove-1,m,n,dp))%mod;
        }
        return dp[startRow][startColumn][maxMove]=result;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(51,vector<vector<int>>(51,vector<int>(51,-1)));
        return solve(startRow,startColumn,maxMove,m,n,dp);
    }
};