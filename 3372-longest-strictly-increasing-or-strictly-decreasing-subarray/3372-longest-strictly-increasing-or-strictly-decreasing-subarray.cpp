class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxLen=1,inc=1,dec=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
            {
                inc++;
                maxLen=max(maxLen,inc);
            }
            else
            inc=1;
        }
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<nums[i-1])
            {
                dec++;
                maxLen=max(maxLen,dec);
            }
            else
            dec=1;
        }
        return maxLen;
    }
};