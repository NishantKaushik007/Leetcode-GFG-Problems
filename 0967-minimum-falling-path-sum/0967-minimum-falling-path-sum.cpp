class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        for(int j=0;j<matrix[0].size();j++)
        dp[0][j]=matrix[0][j];
        for(int i=1;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                int left=1e8;
                if(j-1>=0)
                left=matrix[i][j]+dp[i-1][j-1];
                int down=matrix[i][j]+dp[i-1][j];
                int right=1e8;
                if(j+1<matrix[0].size())
                right=matrix[i][j]+dp[i-1][j+1];
                dp[i][j]=min(left,min(down,right));
            }
        }
        int mini=1e8;
        for(int i=0;i<matrix[0].size();i++)
        mini=min(mini,dp[matrix.size()-1][i]);
        return mini;
    }
};