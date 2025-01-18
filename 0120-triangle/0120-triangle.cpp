class Solution {
public:
    int minSum(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp)
    {
        if(i==triangle.size())
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int down=triangle[i][j]+minSum(i+1,j,triangle,dp);
        int dia=triangle[i][j]+minSum(i+1,j+1,triangle,dp);
        return dp[i][j]=min(down,dia);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp(triangle.size(),vector<int>(triangle.size(),-1));
        for(int i=0;i<triangle.size();i++)
        dp[triangle.size()-1][i]=triangle[triangle.size()-1][i];
        for(int i=triangle.size()-2;i>=0;i--)
        {
            for(int j=triangle.size()-2;j>=0;j--)
            {
                int down=1e8;
                if(j<=i)
                down=triangle[i][j]+dp[i+1][j];
                int dia=1e8;
                if(j<=i)
                dia=triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(down,dia);
            }
        }
        return dp[0][0];
    }
};