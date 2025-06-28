class Solution {
public:
    static bool comp(pair<int,int>& a,pair<int,int>& b)
    {
        return a.second>b.second;
    }
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        v.push_back({i,nums[i]});
        sort(v.begin(),v.end(),comp);
        sort(v.begin(),v.begin()+k);
        for(int i=0;i<k;i++)
        ans.push_back(v[i].second);
        return ans;
    }
};