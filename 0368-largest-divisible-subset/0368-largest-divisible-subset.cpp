class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size(),maxi=1,last_ind=0;
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1),hash(n);
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0&&dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }
            if(dp[i]>maxi)
            {
                maxi=dp[i];
                last_ind=i;
            }
        }
        vector<int>temp;
        temp.push_back(nums[last_ind]);
        while(hash[last_ind]!=last_ind)
        {
            last_ind=hash[last_ind];
            temp.push_back(nums[last_ind]);
        }
        return temp;
    }
};