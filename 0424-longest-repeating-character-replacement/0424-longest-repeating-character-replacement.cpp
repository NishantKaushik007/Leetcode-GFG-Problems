class Solution {
public:
    int characterReplacement(string s, int k) {
        int freq[26]={0},l=0,r=0,maxLen=0,maxFreq=0;
        while(r<s.length())
        {
            freq[s[r]-'A']++;
            maxFreq=max(maxFreq,freq[s[r]-'A']);
            if((r-l+1)-maxFreq>k)
            {
                freq[s[l]-'A']--;
                l++;
            }
            if((r-l+1)-maxFreq<=k)
                maxLen=max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
};