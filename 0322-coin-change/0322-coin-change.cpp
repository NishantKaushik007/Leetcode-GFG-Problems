class Solution {
public:
    int coin(int ind,int amt,vector<int>& coins,vector<vector<int>>& dp)
    {
        if(ind==0)
        {
            if(amt%coins[ind]==0)
            return amt/coins[ind];
            return 1e9;
        }
        if(dp[ind][amt]!=-1)
        return dp[ind][amt];
        int take=1e9;
        if(amt>=coins[ind])
        take=1+coin(ind,amt-coins[ind],coins,dp);
        int notTake=coin(ind-1,amt,coins,dp);
        return dp[ind][amt]=min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int ans=coin(coins.size()-1,amount,coins,dp);
        if(ans>=1e9)
        return -1;
        return ans;
    }
};