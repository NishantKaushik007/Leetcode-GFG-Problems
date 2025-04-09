class Solution {
public:
    int count(int ind,int amt,vector<int>& coins,vector<vector<int>>& dp)
    {
        if(amt==0)
        return 1;
        if(ind==0)
        return amt%coins[0]==0;
        if(dp[ind][amt]!=-1)
        return dp[ind][amt];
        int take=0;
        if(amt>=coins[ind])
        take=count(ind,amt-coins[ind],coins,dp);
        int notTake=count(ind-1,amt,coins,dp);
        return dp[ind][amt]=take+notTake;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return count(coins.size()-1,amount,coins,dp);
    }
};