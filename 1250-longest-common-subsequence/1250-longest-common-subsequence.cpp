class Solution {
public:
    int lcs(int i,int j,string& text1,string& text2,vector<vector<int>>& dp)
    {
        if(i<0||j<0)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        if(text1[i]==text2[j])
        return 1+lcs(i-1,j-1,text1,text2,dp);
        return dp[i][j]=max(lcs(i-1,j,text1,text2,dp),lcs(i,j-1,text1,text2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.length(),vector<int>(text2.length(),-1));
        return lcs(text1.length()-1,text2.length()-1,text1,text2,dp);
    }
};