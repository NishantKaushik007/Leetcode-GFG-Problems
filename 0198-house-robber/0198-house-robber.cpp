class Solution {
public:
    int solve(int ind,vector<int>& nums,vector<int>& dp)
    {
        if(ind<0)
        return 0;
        if(dp[ind]!=-1)
        return dp[ind];
        int take=nums[ind]+solve(ind-2,nums,dp);
        int notTake=0+solve(ind-1,nums,dp);
        return dp[ind]=max(take,notTake);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return solve(nums.size()-1,nums,dp);
    }
};