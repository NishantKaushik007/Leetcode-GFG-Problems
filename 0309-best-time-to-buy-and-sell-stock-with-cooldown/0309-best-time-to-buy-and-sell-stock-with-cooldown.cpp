class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+2,vector<int>(2,0));
        for(int ind=prices.size()-1;ind>=0;ind--)
        {
            for(int buy=0;buy<2;buy++)
            {
                int profit=0;
                if(buy)
                profit=max(-prices[ind]+dp[ind+1][0],0+dp[ind+1][1]);
                else
                profit=max(prices[ind]+dp[ind+2][1],0+dp[ind+1][0]);
                dp[ind][buy]=profit;
            }
        }
        return dp[0][1];
    }
};