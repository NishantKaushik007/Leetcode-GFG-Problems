class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n=groupSizes.size();
        vector<vector<int>>ans;
        
        //key -> val
        //size -> {}
        vector<vector<int>>mp(n+1);          // 0 to n
        for(int i=0;i<n;i++)
        {
            int l=groupSizes[i];
            mp[l].push_back(i);
            if(mp[l].size()==l)
            {
                ans.push_back(mp[l]);
                mp[l]={};
            }
        }
        return ans;
    }
};