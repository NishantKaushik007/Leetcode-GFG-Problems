class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp(triangle.size(),vector<int>(triangle.size(),0));
        for(int i=0;i<triangle.size();i++)
        dp[triangle.size()-1][i]=triangle[triangle.size()-1][i];
        for(int i=triangle.size()-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                int down=triangle[i][j]+dp[i+1][j];
                int right=triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(down,right);
            }
        }
        return dp[0][0];
    }
};