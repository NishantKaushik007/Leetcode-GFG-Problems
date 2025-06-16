class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>ahead1(2,0),ahead2(2,0),curr(2,0);
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=1;buy>=0;buy--)
            {
                int profit=0;
                if(buy)
                profit+=max(-prices[ind]+ahead1[0],ahead1[1]);
                else
                profit+=max(prices[ind]+ahead2[1],ahead1[0]);
                curr[buy]=profit;
            }
            ahead2=ahead1;
            ahead1=curr;
        }
        return ahead1[1];
    }
};