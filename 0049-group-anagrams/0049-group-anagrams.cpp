class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<strs.size();i++)
        {
            int freq[26]={0};
            string str=strs[i],key="";
            for(int j=0;j<strs[i].size();j++)
            {
                freq[strs[i][j]-'a']++;
            }
            for(int i=0;i<26;i++)
            {
                if(freq[i]>0)
                {
                    string s(freq[i],'a'+i);
                    key+=s;
                }
            }
            mp[key].push_back(str);
        }
        for(auto p:mp)
        {
            vector<string>v;
            for(auto q:p.second)
            {
                v.push_back(q);
            }
            ans.push_back(v);
        }
        return ans;
    }
};