class Solution {
public:
    int solve(int ind,vector<int>& nums,int target,vector<vector<int>>& dp)
    {
        if(target==0)
            return 1;
        if(ind>=nums.size()||target<0)
            return 0;
        if(dp[ind][target]!=-1)
            return dp[ind][target];
        int notTake=solve(ind+1,nums,target,dp);
        int take=solve(0,nums,target-nums[ind],dp);
        return dp[ind][target]=notTake+take;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<vector<int>>dp(nums.size(),vector<int>(target+1,-1));
        return solve(0,nums,target,dp);
    }
};