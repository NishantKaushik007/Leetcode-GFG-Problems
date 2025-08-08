class Solution {
public:
    double solve(int A, int B,vector<vector<double>>&dp) {
        if (A <= 0 && B <= 0) return 0.5;
        if (A <= 0) return 1.0;
        if (B <= 0) return 0.0;
        if(dp[A][B]!=-1.0) return dp[A][B];
        double ans = 0;
        
        ans += solve(A - 100, B,dp);
        ans += solve(A - 75, B - 25,dp);
        ans += solve(A - 50, B - 50,dp);
        ans += solve(A - 25, B - 75,dp);
        return dp[A][B]=ans * 0.25;
    }

    double soupServings(int n) {
        if (n >= 5000) return 1.0; 
        vector<vector<double>>dp(n+1,vector<double>(n+1,-1.0));
        return solve(n, n,dp);
    }
};