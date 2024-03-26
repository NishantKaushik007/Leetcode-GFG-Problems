class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int>m;
        int left=0,right=0,maxLen=0;
        while(right<s.length())
        {
            if(m.find(s[right])!=m.end())
                left=max(left,m[s[right]]+1);
            m[s[right]]=right;
            maxLen=max(maxLen,right-left+1);
            right++;
        }
        return maxLen;
    }
};