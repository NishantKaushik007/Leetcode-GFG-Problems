class Solution {
public:
    bool isPalindrome(int start,int end,string& s)
    {
        if(start>=end)
        return true;
        if(s[start]==s[end])
        return isPalindrome(start+1,end-1,s);
        return false;
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