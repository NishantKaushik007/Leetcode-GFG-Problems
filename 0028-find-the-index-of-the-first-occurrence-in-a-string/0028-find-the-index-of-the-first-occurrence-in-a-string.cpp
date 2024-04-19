class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.length(),m=needle.length();
        if(m>n)
            return -1;
        for(int i=0;i<=n-m;i++)
        {
            string s=haystack.substr(i,m);
            if(needle==s)
                return i;
        }
        return -1;
    }
};