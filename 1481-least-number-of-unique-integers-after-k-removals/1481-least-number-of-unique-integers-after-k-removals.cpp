class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>m;
        for(int x:arr)
        {
            m[x]++;
        }
        vector<pair<int,int>>v;
        for(auto x:m)
        {
            v.push_back({x.second,x.first});
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        cout<<endl;
        for(int i=v.size()-1;i>=0;i--)
        {
            if(v[i].first<=k)
            {
                k=k-v[i].first;
                v.pop_back();
            }
        }
        return v.size();
    }
};