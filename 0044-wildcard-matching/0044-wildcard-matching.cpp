class Solution {
public:
    bool solve(int i,int j,string& s,string& p,vector<vector<int>>& dp)
    {
        if(i<0&&j<0)
        return true;
        if(j<0&&i>=0)
        return false;
        if(i<0&&j>=0)
        {
            for(int x=0;x<=j;x++)
            if(p[x]!='*')
            return false;
            return true;
        }
        if(dp[i][j]!=-1)
        return dp[i][j];
        if(s[i]==p[j]||p[j]=='?')
        return dp[i][j]=solve(i-1,j-1,s,p,dp);
        if(p[j]=='*')
        return dp[i][j]=solve(i,j-1,s,p,dp)|solve(i-1,j,s,p,dp);
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        int n=s.length(),m=p.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,s,p,dp);
    }
};