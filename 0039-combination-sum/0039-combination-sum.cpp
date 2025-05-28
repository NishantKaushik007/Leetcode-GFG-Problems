class Solution {
public:
    void solve(int ind,vector<int>& candidates,int target,vector<int>& ds,vector<vector<int>>& ans)
    {
        if(ind==candidates.size())
        return;
        if(target==0)
        {
            ans.push_back(ds);
            return;
        }
        if(candidates[ind]<=target)
        {
            ds.push_back(candidates[ind]);
            solve(ind,candidates,target-candidates[ind],ds,ans);
            ds.pop_back();
        }
        solve(ind+1,candidates,target,ds,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        solve(0,candidates,target,ds,ans);
        return ans;
    }
};