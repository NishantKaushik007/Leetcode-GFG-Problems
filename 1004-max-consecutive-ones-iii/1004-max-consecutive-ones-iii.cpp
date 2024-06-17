class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeros=0,l=0,r=0,maxOnes=0;
        while(r<nums.size())
        {
            if(nums[r]==0)
                zeros++;
            while(zeros>k)
            {
                if(nums[l]==0)
                    zeros--;
                l++;
            }
            if(zeros<=k)
                maxOnes=max(maxOnes,r-l+1);
            r++;
        }
        return maxOnes;
    }
};