class Solution {
public:
    bool checkPossible(string& s,string& t)
    {
        if(s.length()+1!=t.length())
        return false;
        int i=0,j=0;
        while(j<t.length())
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        if(i==s.length()&&j==t.length())
        return true;
        return false;
    }
    static bool comp(string& s1,string& s2)
    {
        return s1.length()<s2.length();
    }
    int longestStrChain(vector<string>& words) {
        int maxLen=1;
        sort(words.begin(),words.end(),comp);
        vector<int>dp(words.size(),1);
        for(int i=1;i<words.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(checkPossible(words[j],words[i])&&dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                    maxLen=max(maxLen,dp[i]);
                }
            }
        }
        return maxLen;
    }
};