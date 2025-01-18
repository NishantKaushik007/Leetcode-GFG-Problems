class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int num:nums)
        sum+=num;
        if(sum%2)
        return false;
        vector<vector<bool>>dp(nums.size(),vector<bool>((sum/2)+1,false));
        for(int i=0;i<nums.size();i++)
        dp[i][0]=true;
        for(int ind=1;ind<nums.size();ind++)
        {
            for(int tar=0;tar<=sum/2;tar++)
            {
                bool notTake=dp[ind-1][tar];
                bool take=false;
                if(tar>=nums[ind])
                take=dp[ind-1][tar-nums[ind]];
                dp[ind][tar]=take|notTake;
            }
        }
        return dp[nums.size()-1][sum/2];
    }
};