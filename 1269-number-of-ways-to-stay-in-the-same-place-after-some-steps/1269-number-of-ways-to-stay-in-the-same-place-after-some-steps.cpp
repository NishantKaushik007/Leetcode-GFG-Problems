class Solution {
public:
    int mod=1e9+7;
    int dp[501][501];
    int num(int pos,int steps,int arrLen)
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
        int res=num(pos,steps-1,arrLen)%mod;
        res=(res+num(pos-1,steps-1,arrLen))%mod;
        res=(res+num(pos+1,steps-1,arrLen))%mod;
        return dp[pos][steps]=res;
    }
    int numWays(int steps, int arrLen) {
        arrLen=min(arrLen,(steps/2+1));
        memset(dp,-1,sizeof(dp));
        return num(0,steps,arrLen);
    }
};