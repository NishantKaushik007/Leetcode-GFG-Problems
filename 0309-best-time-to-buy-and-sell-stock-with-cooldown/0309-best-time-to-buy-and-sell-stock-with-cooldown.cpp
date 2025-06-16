class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+2,vector<int>(3,0));
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=1;buy>=0;buy--)
            {
                int profit=0;
                if(buy)
                profit+=max(-prices[ind]+dp[ind+1][0],dp[ind+1][1]);
                else
                profit+=max(prices[ind]+dp[ind+2][1],dp[ind+1][0]);
                dp[ind][buy]=profit;
            }
        }
        return dp[0][1];
    }
};