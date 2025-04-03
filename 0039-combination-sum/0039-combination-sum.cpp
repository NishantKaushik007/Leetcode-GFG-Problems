class Solution {
public:
    void solve(int ind,int target,vector<int>& candidates,vector<int> ds,vector<vector<int>>& ans)
    {
        if(ind==candidates.size())
        {
            if(target==0)
            ans.push_back(ds);
            return;
        }
        if(candidates[ind]<=target)
        {
            ds.push_back(candidates[ind]);
            solve(ind,target-candidates[ind],candidates,ds,ans);
            ds.pop_back();
        }
        solve(ind+1,target,candidates,ds,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        solve(0,target,candidates,ds,ans);
        return ans;
    }
};