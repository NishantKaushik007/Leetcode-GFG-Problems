class Solution {
public:
    int coinChange(vector<int>& coins, int am) {
        vector<vector<int>>dp(coins.size(),vector<int>(am+1,1e9));
        for(int i=0;i<coins.size();i++)
        dp[i][0]=0;
        for(int i=0;i<=am;i++)
        {
            if(i%coins[0]==0)
            {
                dp[0][i]=i/coins[0];
            }
        }
        for(int ind=1;ind<coins.size();ind++)
        {
            for(int amount=0;amount<=am;amount++)
            {
                int notTake=dp[ind-1][amount];
                int take=1e9;
                if(amount>=coins[ind])
                take=1+dp[ind][amount-coins[ind]];
                dp[ind][amount]=min(take,notTake);
            }
        }
        int ans=dp[coins.size()-1][am];
        if(ans>=1e9)
        return -1;
        return ans;
    }
};