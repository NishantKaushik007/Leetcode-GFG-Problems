class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+1,vector<int>(2*k+1,0));
        for(int ind=prices.size()-1;ind>=0;ind--)
        {
            for(int K=2*k-1;K>=0;K--)
            {
                if(K%2==0)
                dp[ind][K]=max(-prices[ind]+dp[ind+1][K+1],0+dp[ind+1][K]);
                else
                dp[ind][K]=max(prices[ind]+dp[ind+1][K+1],0+dp[ind+1][K]);
            }
        }
        return dp[0][0];
    }
};