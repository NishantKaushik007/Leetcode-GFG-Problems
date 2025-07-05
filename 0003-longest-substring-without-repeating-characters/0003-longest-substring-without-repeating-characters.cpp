class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,maxLen=0;
        unordered_map<char,int>mp;
        while(r<s.length())
        {
            if(mp.find(s[r])!=mp.end())
            l=max(l,mp[s[r]]+1);
            maxLen=max(maxLen,r-l+1);
            mp[s[r]]=r;
            r++;
        }
        return maxLen;
    }
};