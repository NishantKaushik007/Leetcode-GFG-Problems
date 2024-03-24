class Solution {
public:
    int lcs(int i,int j,string& a,string& b,vector<vector<int>>& dp)
    {
        if(i<0||j<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(a[i]==b[j])
            return dp[i][j]=1+lcs(i-1,j-1,a,b,dp);
        return dp[i][j]=max(lcs(i-1,j,a,b,dp),lcs(i,j-1,a,b,dp));
    }
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        int n=s.length();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return lcs(n-1,n-1,s,t,dp);
    }
};