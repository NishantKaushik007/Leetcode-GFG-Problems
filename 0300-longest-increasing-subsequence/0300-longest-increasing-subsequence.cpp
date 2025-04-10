class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int maxLen=1;
        vector<int>dp(nums.size(),1);
        for(int i=1;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i]&&dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                    maxLen=max(maxLen,dp[i]);
                }
            }
        }
        return maxLen;
    }
};