class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>m;
        int l=0,r=0,maxLen=0;
        while(r<s.length())
        {
            if(m.find(s[r])!=m.end())
                l=max(l,m[s[r]]+1);
            m[s[r]]=r;
            maxLen=max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
};