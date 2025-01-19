class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,maxLen=0;
        unordered_map<char,int>m;
        while(r<s.length())
        {
            if(m.find(s[r])!=m.end())
            {
                l=max(l,m[s[r]]);
            }
            maxLen=max(maxLen,r-l);
            m[s[r]]=r;
            r++;
        }
        return maxLen;
    }
};