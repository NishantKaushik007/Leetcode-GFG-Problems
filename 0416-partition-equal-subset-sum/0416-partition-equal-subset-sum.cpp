class Solution {
public:
    bool canPart(int ind,int tar,vector<int>& nums,vector<vector<int>>& dp)
    {
        if(tar==0)
        return true;
        if(ind==0)
        return tar==nums[0];
        if(dp[ind][tar]!=-1)
        return dp[ind][tar];
        bool notTake=canPart(ind-1,tar,nums,dp);
        bool take=false;
        if(tar>=nums[ind])
        take=canPart(ind-1,tar-nums[ind],nums,dp);
        return dp[ind][tar]=take|notTake;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int num:nums)
        sum+=num;
        if(sum%2)
        return false;
        vector<vector<int>>dp(nums.size(),vector<int>((sum/2)+1,-1));
        return canPart(nums.size()-1,sum/2,nums,dp);
    }
};