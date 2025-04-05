class Solution {
public:
    int exor(int ind,int curr,vector<int>& nums)
    {
        if(ind==nums.size())
        return curr;
        int take=exor(ind+1,curr^nums[ind],nums);
        int notTake=exor(ind+1,curr,nums);
        return take+notTake;
    }
    int subsetXORSum(vector<int>& nums) {
        return exor(0,0,nums);
    }
};