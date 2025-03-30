class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>ahead(5,0);
        for(int ind=prices.size()-1;ind>=0;ind--)
        {
            vector<int>curr(5,0);
            for(int trans=3;trans>=0;trans--)
            {
                if(trans%2==0)
                curr[trans]=max(-prices[ind]+ahead[trans+1],0+ahead[trans]);
                else
                curr[trans]=max(prices[ind]+ahead[trans+1],0+ahead[trans]);
            }
            ahead=curr;
        }
        return ahead[0];
    }
};