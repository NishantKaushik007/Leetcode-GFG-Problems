class Solution {
public:
    int mod=1e9+7;
    int num(int pos,int steps,int arrLen,vector<vector<int>> &dp)
    {
        if(steps==0)
        {
            if(pos==0)
            return 1;
            return 0;
        }
        if(pos>=arrLen||pos<0)
        {
            return 0;
        }
        if(dp[pos][steps]!=-1)
            return dp[pos][steps];
        int res=num(pos,steps-1,arrLen,dp)%mod;
        res=(res+num(pos-1,steps-1,arrLen,dp))%mod;
        res=(res+num(pos+1,steps-1,arrLen,dp))%mod;
        return dp[pos][steps]=res;
    }
    int numWays(int steps, int arrLen) {
        vector<vector<int>>dp(steps+1,vector<int>(steps+1,-1));
        return num(0,steps,arrLen,dp);
    }
};