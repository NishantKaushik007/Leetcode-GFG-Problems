class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size(),maxi=1,ans=0;
        vector<int>dp(n,1),count(n,1);
        for(int ind=0;ind<n;ind++)
        {
            for(int prev_ind=0;prev_ind<ind;prev_ind++)
            {
                if(nums[ind]>nums[prev_ind]&&1+dp[prev_ind]>dp[ind])
                {
                    dp[ind]=1+dp[prev_ind];
                    //inherit
                    count[ind]=count[prev_ind];
                }
                else if(nums[ind]>nums[prev_ind]&&1+dp[prev_ind]==dp[ind])
                {
                    //increase the count
                    count[ind]+=count[prev_ind];
                }
            }
            maxi=max(maxi,dp[ind]);
        }
        for(int i=0;i<n;i++)
        {
            if(dp[i]==maxi)
            ans+=count[i];
        }
        return ans;
    }
};