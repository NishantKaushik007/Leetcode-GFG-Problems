class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size(),l=0,r=0,sum=0,maxSum=0;
        unordered_map<int,int>mp;
        while(r<n)
        {
            while(mp.find(nums[r])!=mp.end())
            {
                sum-=nums[l];
                mp.erase(nums[l]);
                l++;
            }
            sum+=nums[r];
            mp[nums[r]]=r;
            maxSum=max(maxSum,sum);
            r++;
        }
        return maxSum;
    }
};