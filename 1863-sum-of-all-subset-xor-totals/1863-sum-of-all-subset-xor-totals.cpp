class Solution {
public:
    void allSubset(int ind,vector<int>& nums,vector<int>& ds,vector<vector<int>>& subset)
    {
        if(ind==nums.size())
        {
            subset.push_back(ds);
            return;
        }
        ds.push_back(nums[ind]);
        allSubset(ind+1,nums,ds,subset);
        ds.pop_back();
        allSubset(ind+1,nums,ds,subset);
    }
    int subsetXORSum(vector<int>& nums) {
        int sum=0;
        vector<vector<int>>subset;
        vector<int>ds;
        allSubset(0,nums,ds,subset);
        for(auto nums:subset)
        {
            int exor=0;
            for(int num:nums)
            {
                exor^=num;
            }
            sum+=exor;
        }
        return sum;
    }
};