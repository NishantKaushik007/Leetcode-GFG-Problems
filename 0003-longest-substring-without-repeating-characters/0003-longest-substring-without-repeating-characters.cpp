class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>index(256,-1);
        int left=0,right=0,maxLen=0;
        while(right<s.length())
        {
            if(index[s[right]]!=-1)
                left=max(left,index[s[right]]+1);
            index[s[right]]=right;
            maxLen=max(maxLen,right-left+1);
            right++;
        }
        return maxLen;
    }
};