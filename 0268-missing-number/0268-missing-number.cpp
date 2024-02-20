class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int nSum=(nums.size()*(nums.size()+1))/2,sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        return nSum-sum;
    }
};