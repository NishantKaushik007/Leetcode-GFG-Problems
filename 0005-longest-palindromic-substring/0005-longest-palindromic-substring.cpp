class Solution {
public:
    int dp[1001][1001];
    bool isPalindrome(int start,int end,string& s)
    {
        if(start>=end)
        return 1;
        if(dp[start][end]!=-1)
        return dp[start][end];
        if(s[start]==s[end])
        return dp[start][end]=isPalindrome(start+1,end-1,s);
        return dp[start][end]=0;
    }
    string longestPalindrome(string s) {
        int start=-1,maxLen=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<s.length();i++)
        {
            for(int j=i;j<s.length();j++)
            {
                if(isPalindrome(i,j,s))
                {
                    if(j-i+1>maxLen)
                    {
                        maxLen=j-i+1;
                        start=i;
                    }
                }
            }
        }
        return s.substr(start,maxLen);
    }
};