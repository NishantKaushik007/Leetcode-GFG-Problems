class Solution {
public:
    int coin(int ind,vector<int>& coins, int amount,vector<vector<int>>& dp)
    {
        if(ind==0)
        {
            if(amount%coins[ind]==0)
                return amount/coins[ind];
            return 1e9;
        }
        if(dp[ind][amount]!=-1)
            return dp[ind][amount];
        int notTake=0+coin(ind-1,coins,amount,dp);
        int take=1e9;
        if(amount>=coins[ind])
        take=1+coin(ind,coins,amount-coins[ind],dp);
        return dp[ind][amount]=min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int ans=coin(coins.size()-1,coins,amount,dp);
        if(ans==1e9)
            return -1;
        return ans;
    }
};