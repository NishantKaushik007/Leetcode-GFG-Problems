class Solution {
public:
    static bool comp(pair<int,char>& a,pair<int,char>& b)
    {
        return a.first>b.first;
    }
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(char c:s)
        mp[c]++;
        vector<pair<int,char>>v;
        for(auto it:mp)
        {
            char c=it.first;
            int freq=it.second;
            v.push_back({freq,c});
        }
        sort(v.begin(),v.end(),comp);
        string ans="";
        for(int i=0;i<v.size();i++)
        {
            int time=v[i].first;
            char c=v[i].second;
            while(time--)
            ans+=c;
        }
        return ans;
    }
};