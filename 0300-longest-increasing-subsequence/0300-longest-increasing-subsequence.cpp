class Solution {
public:
    int lis(int ind,int prev,vector<int>& nums,vector<vector<int>>& dp)
    {
        if(ind>=nums.size())
        return 0;
        if(dp[ind][prev+1]!=-1)
        return dp[ind][prev+1];
        int notTake=0+lis(ind+1,prev,nums,dp);
        int take=0;
        if(prev==-1||nums[ind]>nums[prev])
        take=1+lis(ind+1,ind,nums,dp);
        return dp[ind][prev+1]=max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
        return lis(0,-1,nums,dp);
    }
};