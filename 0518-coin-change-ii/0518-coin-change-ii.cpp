class Solution {
public:
    int change(int am, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(am+1,0));
        for(int i=0;i<=am;i++)
        {
            if(i%coins[0]==0)
            {
                dp[0][i]=1;
            }
        }
        for(int i=0;i<coins.size();i++)
        {
            dp[i][0]=1;
        }
        for(int ind=1;ind<coins.size();ind++)
        {
            for(int amount=0;amount<=am;amount++)
            {
                long notTake=dp[ind-1][amount];
                long take=0;
                if(amount>=coins[ind])
                take=dp[ind][amount-coins[ind]];
                dp[ind][amount]=take+notTake;
            }
        }
        return dp[coins.size()-1][am];
    }
};