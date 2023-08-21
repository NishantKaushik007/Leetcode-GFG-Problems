class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for(int len=1;len<=s.length()/2;len++)
        {
            string newStr="";
            if(s.length()%len==0)
            {
                int times=s.length()/len;
                string pattern=s.substr(0,len);
                while(times--)
                {
                    newStr+=pattern;
                }
                if(newStr==s)
                    return true;
            }
        }
        return false;
    }
};