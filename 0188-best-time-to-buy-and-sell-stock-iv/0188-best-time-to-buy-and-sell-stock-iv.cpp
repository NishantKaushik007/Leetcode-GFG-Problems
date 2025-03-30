class Solution {
public:
    int solve(int ind,int k,vector<int>& prices,vector<vector<int>>& dp)
    {
        if(ind==prices.size()||k==0)
        return 0;
        if(dp[ind][k]!=-1)
        return dp[ind][k];
        if(k%2==0)
        return dp[ind][k]=max(-prices[ind]+solve(ind+1,k-1,prices,dp),0+solve(ind+1,k,prices,dp));
        else
        return dp[ind][k]=max(prices[ind]+solve(ind+1,k-1,prices,dp),0+solve(ind+1,k,prices,dp));
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2*k+1,-1));
        return solve(0,2*k,prices,dp);
    }
};