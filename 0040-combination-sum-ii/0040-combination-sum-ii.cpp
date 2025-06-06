class Solution {
public:
    void solve(int ind,vector<int>& candidates,int target,vector<int>& ds,vector<vector<int>>& ans)
    {
        if(target==0)
        {
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<candidates.size();i++)
        {
            if(i!=ind&&candidates[i]==candidates[i-1])
            continue;
            if(candidates[i]<=target)
            {
                ds.push_back(candidates[i]);
                solve(i+1,candidates,target-candidates[i],ds,ans);
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        sort(candidates.begin(),candidates.end());
        solve(0,candidates,target,ds,ans);
        return ans;
    }
};