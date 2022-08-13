class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>m(256,-1);
        int l=0,r=0,len=0;
        while(r!=s.length())
        {
            if(m[s[r]]!=-1)
            l=max(m[s[r]]+1,l);
            m[s[r]]=r;
            len=max(len,r-l+1);
            r++;
        }
        return len;
    }
};