class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int maxLen=1,count=0;
        vector<int>dp(nums.size(),1),cnt(nums.size(),1);
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i]&&dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                    cnt[i]=cnt[j];
                }
                else if(nums[j]<nums[i]&&1+dp[j]==dp[i])
                {
                    cnt[i]+=cnt[j];
                }
            }
            maxLen=max(maxLen,dp[i]);
        }
        for(int i=0;i<dp.size();i++)
        {
            if(dp[i]==maxLen)
            count+=cnt[i];
        }
        return count;
    }
};