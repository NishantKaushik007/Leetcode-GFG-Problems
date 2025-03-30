class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>ahead(2,0);
        for(int ind=prices.size()-1;ind>=0;ind--)
        {
            vector<int>curr(2,0);
            for(int buy=0;buy<2;buy++)
            {
                int profit=0;
                if(buy)
                profit=max(-prices[ind]+ahead[0],0+ahead[1]);
                else
                profit=max(prices[ind]+ahead[1],0+ahead[0]);
                curr[buy]=profit;
                ahead=curr;
            }
        }
        return ahead[1];
    }
};