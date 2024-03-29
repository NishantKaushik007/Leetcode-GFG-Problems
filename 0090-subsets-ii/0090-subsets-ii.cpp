class Solution {
public:
    void solve(int ind,vector<int>& nums,vector<vector<int>>& ans,vector<int>& subset)
    {
        ans.push_back(subset);
        for(int i=ind;i<nums.size();i++)
        {
            if(i>ind&&nums[i]==nums[i-1])
                continue;
            subset.push_back(nums[i]);
            solve(i+1,nums,ans,subset);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>subset;
        sort(nums.begin(),nums.end());
        solve(0,nums,ans,subset);
        return ans;
    }
};