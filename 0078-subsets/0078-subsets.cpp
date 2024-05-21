class Solution {
public:
    void sub(int ind,vector<int>& nums,vector<vector<int>>& subset,vector<int>& ds)
    {
        if(ind==nums.size())
        {
            subset.push_back(ds);
            return;
        }
        ds.push_back(nums[ind]);
        sub(ind+1,nums,subset,ds);
        ds.pop_back();
        sub(ind+1,nums,subset,ds);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>subset;
        vector<int>ds;
        sub(0,nums,subset,ds);
        return subset;
    }
};