class Solution {
public:
    int solve(int i,int j,string& text1,string& text2,vector<vector<int>>& dp)
    {
        if(i<0||j<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(text1[i]==text2[j])
            return dp[i][j]=1+solve(i-1,j-1,text1,text2,dp);
        return dp[i][j]=max(solve(i-1,j,text1,text2,dp),solve(i,j-1,text1,text2,dp));
    }
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        vector<vector<int>>dp(s.size(),vector<int>(t.size(),-1));
        return solve(s.size()-1,t.size()-1,s,t,dp);
    }
};