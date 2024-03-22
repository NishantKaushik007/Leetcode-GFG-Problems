class Solution {
public:
    bool solve(int ind,int sum,vector<int> &arr,vector<vector<int>>& dp)
    {
        if(sum==0)
        return true;
        if(ind==0)
        {
            return arr[0]==sum;
        }
        if(dp[ind][sum]!=-1)
        return dp[ind][sum];
        bool take=false;
        if(arr[ind]<=sum)
        take=solve(ind-1,sum-arr[ind],arr,dp);
        bool notTake=solve(ind-1,sum,arr,dp);
        return dp[ind][sum]=take||notTake;
    }
    bool canPartition(vector<int>& nums) {
        int k=0;
        for(int i=0;i<nums.size();i++)
            k+=nums[i];
        if(k%2==1)
            return false;
        vector<vector<int>>dp(nums.size(),vector<int>(k/2+1,-1));
        return solve(nums.size()-1,k/2,nums,dp);
    }
};