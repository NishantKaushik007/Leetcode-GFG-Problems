class Solution {
public:
    void combination(vector<int>& candidates,int target,int index,vector<int>& ds,vector<vector<int>>& ans)
    {
        if(target==0)
        {
            ans.push_back(ds);
            return;
        }
        for(int i=index;i<candidates.size();i++)
        {
            if(i>index&&candidates[i]==candidates[i-1])
                continue;
            if(candidates[i]>target)
            break;
            ds.push_back(candidates[i]);
            combination(candidates,target-candidates[i],i+1,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        sort(candidates.begin(),candidates.end());
        combination(candidates,target,0,ds,ans);
        return ans;
    }
};