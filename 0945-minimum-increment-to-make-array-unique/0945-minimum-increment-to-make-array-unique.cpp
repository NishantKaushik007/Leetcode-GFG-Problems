class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int count=0;
        sort(nums.begin(),nums.end());
        int i=0,j=1;
        while(j<nums.size())
        {
            if(nums[j]<=nums[i])
            {
                count+=(nums[i]-nums[j]+1);
                nums[j]=nums[i]+1;
            }
            i++;
            j++;
        }
        return count;
    }
};