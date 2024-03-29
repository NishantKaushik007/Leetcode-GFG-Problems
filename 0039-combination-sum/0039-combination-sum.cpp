class Solution {
public:
    void solve(int ind,int target,vector<int>& nums,vector<vector<int>>& ans,vector<int>& candidates)
    {
        if(ind==candidates.size())
        {
            if(target==0)
            ans.push_back(nums);
            return;
        }
        if(ind<0&&target!=0)
            return;
        if(target>=candidates[ind])
        {
            nums.push_back(candidates[ind]);
            solve(ind,target-candidates[ind],nums,ans,candidates);
            nums.pop_back();
        }
        solve(ind+1,target,nums,ans,candidates);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>nums;
        int n=candidates.size();
        solve(0,target,nums,ans,candidates);
        return ans;
    }
};