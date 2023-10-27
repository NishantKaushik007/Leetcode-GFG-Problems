class Solution {
public:
    bool isPalindrome(string &s,int l,int r,vector<vector<int>> &dp)
    {
        if(l>=r)
            return 1;
        if(dp[l][r]!=-1)
            return dp[l][r];
        if(s[l]!=s[r])
            return 0;
        return dp[l][r]=isPalindrome(s,l+1,r-1,dp);
    }
    string longestPalindrome(string s) {
        int maxLen=INT_MIN,starting=0;
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));
        for(int i=0;i<s.size();i++)
        {
            for(int j=i;j<s.size();j++)
            {
                if(isPalindrome(s,i,j,dp))
                {
                    if(j-i+1>maxLen)
                    {
                        maxLen=j-i+1;
                        starting=i;
                    }
                }
            }
        }
        return s.substr(starting,maxLen);
    }
};