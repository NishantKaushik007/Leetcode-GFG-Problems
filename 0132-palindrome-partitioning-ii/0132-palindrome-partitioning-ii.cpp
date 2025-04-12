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
    int minCut(string s) {
        vector<int>dp(s.length()+1,0);
        for(int i=s.length()-1;i>=0;i--)
        {
            int mini=INT_MAX;
            for(int ind=i;ind<s.length();ind++)
            {
                if(isPalindrome(i,ind,s))
                mini=min(mini,1+dp[ind+1]);
            }
            dp[i]=mini;
        }
        return dp[0]-1;
    }
};