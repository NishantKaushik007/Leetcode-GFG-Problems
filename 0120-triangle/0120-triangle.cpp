class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp)
    {
        if(i==triangle.size()-1)
        return triangle[i][j];
        if(dp[i][j]!=-1)
        return dp[i][j];
        int down=triangle[i][j]+solve(i+1,j,triangle,dp);
        int right=triangle[i][j]+solve(i+1,j+1,triangle,dp);
        return dp[i][j]=min(down,right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp(triangle.size(),vector<int>(triangle.size(),-1));
        return solve(0,0,triangle,dp);
    }
};