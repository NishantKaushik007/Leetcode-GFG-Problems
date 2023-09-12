class Solution {
public:
    int minDeletions(string s) {
        vector<int>freq(26,0);
        int count=0;
        for(int i=0;i<s.length();i++)
        {
            freq[s[i]-'a']++;
        }
        unordered_set<int>set;
        for(int i=0;i<26;i++)
        {
            while(set.find(freq[i])!=set.end()&&freq[i]!=0)
            {
                freq[i]--;
                count++;
            }
            set.insert(freq[i]);
        }
        return count;
    }
};