class Solution {
public:
    int solve(int ind,int amount,vector<int>& coins,vector<vector<int>>& dp)
    {
        if(ind==0)
        {
            if(amount%coins[ind]==0)
            return amount/coins[ind];
            return 1e9;
        }
        if(dp[ind][amount]!=-1)
        return dp[ind][amount];
        int notTake=solve(ind-1,amount,coins,dp);
        int take=1e9;
        if(amount>=coins[ind])
        take=1+solve(ind,amount-coins[ind],coins,dp);
        return dp[ind][amount]=min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int ans=solve(coins.size()-1,amount,coins,dp);
        if(ans>=1e9)
        return -1;
        return ans;
    }
};