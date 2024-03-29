class Solution {
public:
    void solve(int ind,int target,vector<int>& candidates,vector<int>& sum,vector<vector<int>>& ans)
    {
        if(target==0)
        {
            ans.push_back(sum);
            return;
        }
        for(int i=ind;i<candidates.size();i++)
        {
            if(i>ind&&candidates[i]==candidates[i-1])
                continue;
            if(candidates[i]<=target)
            {
                sum.push_back(candidates[i]);
                solve(i+1,target-candidates[i],candidates,sum,ans);
                sum.pop_back();
            }
            else
                break;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>sum;
        sort(candidates.begin(),candidates.end());
        solve(0,target,candidates,sum,ans);
        return ans;
    }
};