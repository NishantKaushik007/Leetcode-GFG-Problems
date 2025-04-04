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
    string longestPalindrome(string s) {
        int start=-1,maxLen=0;
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