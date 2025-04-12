class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,maxLen=0,hash[26]={0},maxFreq=0;
        while(r<s.length())
        {
            hash[s[r]-'A']++;
            maxFreq=max(maxFreq,hash[s[r]-'A']);
            while((r-l+1)-maxFreq>k)
            {
                hash[s[l]-'A']--;
                l++;
            }
            maxLen=max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
};