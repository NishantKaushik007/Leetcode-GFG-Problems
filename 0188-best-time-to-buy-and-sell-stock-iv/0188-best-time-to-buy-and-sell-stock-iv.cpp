class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int>ahead(2*k+1,0);
        for(int ind=prices.size()-1;ind>=0;ind--)
        {
            vector<int>curr(2*k+1,0);
            for(int K=2*k-1;K>=0;K--)
            {
                if(K%2==0)
                curr[K]=max(-prices[ind]+ahead[K+1],0+ahead[K]);
                else
                curr[K]=max(prices[ind]+ahead[K+1],0+ahead[K]);
            }
            ahead=curr;
        }
        return ahead[0];
    }
};