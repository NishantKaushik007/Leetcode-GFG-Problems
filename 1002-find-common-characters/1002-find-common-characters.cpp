class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string>ans;
        int finalFreq[26]={0};
        for(int i=0;i<words[0].length();i++)
            finalFreq[words[0][i]-'a']++;
        for(int i=1;i<words.size();i++)
        {
            int freq[26]={0};
            for(int j=0;j<words[i].length();j++)
            {
                freq[words[i][j]-'a']++;
            }
            for(int k=0;k<26;k++)
            {
                finalFreq[k]=min(finalFreq[k],freq[k]);
            }
        }
        for(int i=0;i<26;i++)
        {
            while(finalFreq[i]!=0)
            {
                finalFreq[i]--;
                ans.push_back(string(1,'a'+i));
            }
        }
        return ans;
    }
};