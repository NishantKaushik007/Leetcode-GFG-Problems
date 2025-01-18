class Solution {
public:
    int money(int ind,vector<int>& nums,vector<int>& dp)
    {
        if(ind<0)
        return 0;
        if(dp[ind]!=-1)
        return dp[ind];
        int notTake=money(ind-1,nums,dp);
        int take=nums[ind]+money(ind-2,nums,dp);
        return dp[ind]=max(take,notTake);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return money(nums.size()-1,nums,dp);
    }
};