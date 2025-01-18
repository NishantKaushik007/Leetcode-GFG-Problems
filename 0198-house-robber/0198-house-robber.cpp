class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),0);
        dp[0]=nums[0];
        for(int ind=1;ind<nums.size();ind++)
        {
            int notTake=dp[ind-1];
            int take=nums[ind];
            if(ind>1)
            take+=dp[ind-2];
            dp[ind]=max(take,notTake);
        }
        return dp[nums.size()-1];
    }
};