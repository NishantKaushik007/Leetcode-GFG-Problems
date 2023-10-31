class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int>ans;
        ans.push_back(pref[0]);
        int prev=pref[0];
        for(int i=1;i<pref.size();i++)
        {
            int num=prev^pref[i];
            prev=prev^num;
            ans.push_back(num);
        }
        return ans;
    }
};