class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,0));
        for(int i=0;i<coins.size();i++)
        dp[i][0]=1;
        for(int i=0;i<=amount;i++)
        {
            if(i%coins[0]==0)
            dp[0][i]=1;
        }
        for(int ind=1;ind<coins.size();ind++)
        {
            for(int amt=0;amt<=amount;amt++)
            {
                int take=0;
                if(amt>=coins[ind])
                take=dp[ind][amt-coins[ind]];
                int notTake=dp[ind-1][amt];
                dp[ind][amt]=take+notTake;
            }
        }
        return dp[coins.size()-1][amount];
    }
};