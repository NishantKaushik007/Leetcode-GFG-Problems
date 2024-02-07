class Solution {
public:
    string frequencySort(string s) {
        string ans="";
        unordered_map<char,int>m;
        for(auto x:s)
        {
            m[x]++;
        }
        vector<pair<int,char>>res;
        for(auto x:m)
        {
            res.push_back({x.second,x.first});
        }
        sort(res.begin(),res.end());
        for(auto x:res)
        {
            while(x.first!=0)
            {
                ans+=x.second;
                x.first--;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};