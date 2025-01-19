class Solution {
public:
    int coinChange(vector<int>& coins, int am) {
        vector<int>prev(am+1,1e9);
        for(int i=0;i<coins.size();i++)
        prev[0]=0;
        for(int i=0;i<=am;i++)
        {
            if(i%coins[0]==0)
            {
                prev[i]=i/coins[0];
            }
        }
        for(int ind=1;ind<coins.size();ind++)
        {
            vector<int>curr(am+1,1e9);
            for(int amount=0;amount<=am;amount++)
            {
                int notTake=prev[amount];
                int take=1e9;
                if(amount>=coins[ind])
                take=1+curr[amount-coins[ind]];
                curr[amount]=min(take,notTake);
            }
            prev=curr;
        }
        int ans=prev[am];
        if(ans>=1e9)
        return -1;
        return ans;
    }
};