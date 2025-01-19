class Solution {
public:
    int change(int am, vector<int>& coins) {
        vector<int>prev(am+1,0);
        for(int i=0;i<=am;i++)
        {
            if(i%coins[0]==0)
            {
                prev[i]=1;
            }
        }
        for(int i=0;i<coins.size();i++)
        {
            prev[0]=1;
        }
        for(int ind=1;ind<coins.size();ind++)
        {
            vector<int>curr(am+1,0);
            for(int amount=0;amount<=am;amount++)
            {
                long notTake=prev[amount];
                long take=0;
                if(amount>=coins[ind])
                take=curr[amount-coins[ind]];
                curr[amount]=take+notTake;
            }
            prev=curr;
        }
        return prev[am];
    }
};