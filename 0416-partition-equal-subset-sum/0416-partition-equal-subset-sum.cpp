class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int num:nums)
        sum+=num;
        if(sum%2==1)
        return false;
        vector<vector<int>>dp(nums.size(),vector<int>(sum/2+1,0));
        for(int i=0;i<nums.size();i++)
        dp[i][0]=1;
        if(nums[0]<=sum/2)
        dp[0][nums[0]]=1;
        for(int ind=1;ind<nums.size();ind++)
        {
            for(int target=1;target<=sum/2;target++)
            {
                bool take=false;
                if(nums[ind]<=target)
                take=dp[ind-1][target-nums[ind]];
                bool notTake=dp[ind-1][target];
                dp[ind][target]=take|notTake;
            }
        }
        return dp[nums.size()-1][sum/2];
    }
};