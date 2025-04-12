class Solution {
public:
    bool isPalindrome(int start,int end,string& s)
    {
        while(start<=end)
        {
            if(s[start++]!=s[end--])
            return false;
        }
        return true;
    }
    int solve(int i,string& s,vector<int>& dp)
    {
        if(i==s.length())
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        int mini=INT_MAX;
        for(int ind=i;ind<s.length();ind++)
        {
            if(isPalindrome(i,ind,s))
            mini=min(mini,1+solve(ind+1,s,dp));
        }
        return dp[i]=mini;
    }
    int minCut(string s) {
        vector<int>dp(s.length(),-1);
        return solve(0,s,dp)-1;
    }
};