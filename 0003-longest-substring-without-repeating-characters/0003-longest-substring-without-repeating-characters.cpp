class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int l=0,r=0,maxLen=0;
        while(r<s.length())
        {
            if(mp.find(s[r])!=mp.end()&&mp[s[r]]>=l)
                l=mp[s[r]]+1;
            maxLen=max(maxLen,r-l+1);
            mp[s[r]]=r;
            r++;
        }
        return maxLen;
    }
};