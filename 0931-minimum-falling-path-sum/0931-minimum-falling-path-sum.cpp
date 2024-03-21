class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp)
    {
        if(j<0||j>=matrix[0].size())
            return 1e8;
        if(i==0)
        {
            return matrix[0][j];;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        int left=matrix[i][j]+solve(i-1,j-1,matrix,dp);
        int up=matrix[i][j]+solve(i-1,j,matrix,dp);
        int right=matrix[i][j]+solve(i-1,j+1,matrix,dp);
        return dp[i][j]=min(left,min(up,right));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        for(int j=0;j<matrix[0].size();j++)
        dp[0][j]=matrix[0][j];
        for(int i=1;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                int left=matrix[i][j];
                if(j-1>=0)
                left+=dp[i-1][j-1];
                else
                    left+=1e8;
                int up=matrix[i][j]+dp[i-1][j];
                int right=matrix[i][j];
                if(j+1<matrix[0].size())
                right+=dp[i-1][j+1];
                else
                    right+=1e8;
                dp[i][j]=min(left,min(up,right));
            }
        }
        int mini=INT_MAX;
        for(int j=0;j<matrix[0].size();j++)
        mini=min(mini,dp[matrix.size()-1][j]);
        return mini;
    }
};