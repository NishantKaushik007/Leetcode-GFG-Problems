class Solution {
public:
    int dis(int i,int j,string word1, string word2,vector<vector<int>>& dp)
    {
        if(i<0&&j<0)
        return 0;
        if(i<0&&j>=0)
        return j+1;
        if(j<0&&i>=0)
        return i+1;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int match=1e9;
        if(word1[i]==word2[j])
        match=dis(i-1,j-1,word1,word2,dp);
        int notMatch=1+min(dis(i-1,j,word1,word2,dp),dis(i,j-1,word1,word2,dp));
        return dp[i][j]=min(match,notMatch);
    }
    int minDistance(string word1, string word2) {
        int n=word1.length(),m=word2.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return dis(n-1,m-1,word1,word2,dp);
    }
};