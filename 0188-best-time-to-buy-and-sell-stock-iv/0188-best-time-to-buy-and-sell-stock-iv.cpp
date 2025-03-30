class Solution {
public:
    int solve(int ind,int K,vector<int>& prices,vector<vector<int>>& dp,int k)
    {
        if(ind==prices.size()||K==2*k)
        return 0;
        if(dp[ind][K]!=-1)
        return dp[ind][K];
        if(K%2==0)
        return dp[ind][K]=max(-prices[ind]+solve(ind+1,K+1,prices,dp,k),0+solve(ind+1,K,prices,dp,k));
        else
        return dp[ind][K]=max(prices[ind]+solve(ind+1,K+1,prices,dp,k),0+solve(ind+1,K,prices,dp,k));
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2*k+1,-1));
        return solve(0,0,prices,dp,k);
    }
};