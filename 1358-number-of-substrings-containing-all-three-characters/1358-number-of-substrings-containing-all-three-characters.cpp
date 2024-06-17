class Solution {
public:
    int numberOfSubstrings(string s) {
        int freq[3]={-1,-1,-1},count=0;
        for(int i=0;i<s.length();i++)
        {
            freq[s[i]-'a']=i;
            count+=min(freq[0],min(freq[1],freq[2]))+1;
        }
        return count;
    }
};