class Solution {
public:
    bool subSum(int ind,int target,vector<int>& nums,vector<vector<int>>& dp)
    {
        if(ind<0)
        return false;
        if(target==0)
        return true;
        if(dp[ind][target]!=-1)
        return dp[ind][target];
        bool take=false;
        if(nums[ind]<=target)
        take=subSum(ind-1,target-nums[ind],nums,dp);
        bool notTake=subSum(ind-1,target,nums,dp);
        return dp[ind][target]=take|notTake;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int num:nums)
        sum+=num;
        if(sum%2==1)
        return false;
        vector<vector<int>>dp(nums.size(),vector<int>(sum/2+1,-1));
        return subSum(nums.size()-1,sum/2,nums,dp);
    }
};