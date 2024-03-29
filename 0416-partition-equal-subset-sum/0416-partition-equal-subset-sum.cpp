class Solution {
public:
    bool solve(int ind,int target,vector<int>& nums,vector<vector<int>>& dp)
    {
        if(target==0)
            return true;
        if(ind<0&&target!=0)
            return false;
        if(dp[ind][target]!=-1)
            return dp[ind][target];
        bool notTake=solve(ind-1,target,nums,dp);
        bool take=false;
        if(nums[ind]<=target)
            take=solve(ind-1,target-nums[ind],nums,dp);
        return dp[ind][target]=take|notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size(),sum=0,target=0;
        for(int i=0;i<n;i++)
            sum+=nums[i];
        if(sum%2==1)
            return false;
        target=sum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return solve(n-1,target,nums,dp);
    }
};