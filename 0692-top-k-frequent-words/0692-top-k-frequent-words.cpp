class Solution {
public:
    static bool customComparator(const pair<int, string> &a, const pair<int, string> &b) {
        if (a.first != b.first)
            return a.first > b.first; // descending order of first
        return a.second < b.second;   // ascending order of second
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string>ans;
        unordered_map<string,int>mp;
        for(string s:words)
        mp[s]++;
        vector<pair<int,string>>v;
        for(auto it:mp)
        {
            v.push_back({it.second,it.first});
        }
        sort(v.begin(), v.end(), customComparator);
        int i=0;
        while(k--)
        {
            ans.push_back(v[i].second);
            i++;
        }
        return ans;
    }
};