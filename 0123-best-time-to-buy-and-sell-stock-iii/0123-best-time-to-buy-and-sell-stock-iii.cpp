class Solution {
public:
    int solve(int ind,int trans,vector<int>& prices,vector<vector<int>>& dp)
    {
        if(trans==4)
        return 0;
        if(ind==prices.size())
        return 0;
        if(dp[ind][trans]!=-1)
        return dp[ind][trans];
        if(trans%2==0)
        return dp[ind][trans]=max(-prices[ind]+solve(ind+1,trans+1,prices,dp),0+solve(ind+1,trans,prices,dp));
        else
        return dp[ind][trans]=max(prices[ind]+solve(ind+1,trans+1,prices,dp),0+solve(ind+1,trans,prices,dp));
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(4,-1));
        return solve(0,0,prices,dp);
    }
};