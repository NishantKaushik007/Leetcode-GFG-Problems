class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            int fs=dp[i-1];
            int ss=dp[i-2];
            dp[i]=fs+ss;
        }
        return dp[n];
    }
};