class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,0));
        for(int amt=0;amt<=amount;amt++)
        {
            if(amt%coins[0]==0)
            dp[0][amt]=amt/coins[0];
            else
            dp[0][amt]=1e9;
        }
        for(int ind=1;ind<coins.size();ind++)
        {
            for(int amt=0;amt<=amount;amt++)
            {
                int take=1e9;
                if(amt>=coins[ind])
                take=1+dp[ind][amt-coins[ind]];
                int notTake=dp[ind-1][amt];
                dp[ind][amt]=min(take,notTake);
            }
        }
        int ans=dp[coins.size()-1][amount];
        if(ans>=1e9)
        return -1;
        return ans;
    }
};