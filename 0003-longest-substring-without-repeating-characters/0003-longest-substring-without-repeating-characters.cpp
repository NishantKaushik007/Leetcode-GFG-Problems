class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,maxLen=0;
        unordered_map<char,int>m;
        while(r<s.length())
        {
            if(m.find(s[r])!=m.end())
            {
                l=max(l,m[s[r]]+1);
            }
            maxLen=max(maxLen,r-l+1);
            m[s[r]]=r;
            r++;
        }
        return maxLen;
    }
};