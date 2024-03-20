class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=prices[0],maxi=0;
        for(int i=1;i<prices.size();i++)
        {
            minPrice=min(minPrice,prices[i]);
            maxi=max(maxi,prices[i]-minPrice);
        }
        return maxi;
    }
};