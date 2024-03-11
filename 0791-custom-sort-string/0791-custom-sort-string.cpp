class Solution {
public:
    string customSortString(string order, string s) {
        string ans="";
        int freq[26]={0};
        for(int i=0;i<s.length();i++)
        {
            freq[s[i]-'a']++;
        }
        for(int i=0;i<order.length();i++)
        {
            int count=freq[order[i]-'a'];
            freq[order[i]-'a']=0;
            while(count--)
            {
                ans+=order[i];
            }
        }
        for(int i=0;i<26;i++)
        {
            while(freq[i]!=0)
            {
                ans+=char('a'+i);
                freq[i]--;
            }
        }
        return ans;
    }
};