class Solution {
public:
    bool isPalindrome(string &s,int l,int r)
    {
        if(l>=r)
            return true;
        if(s[l]!=s[r])
            return false;
        return isPalindrome(s,l+1,r-1);
    }
    string longestPalindrome(string s) {
        int maxLen=INT_MIN,starting=0;
        for(int i=0;i<s.size();i++)
        {
            for(int j=i;j<s.size();j++)
            {
                if(isPalindrome(s,i,j))
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