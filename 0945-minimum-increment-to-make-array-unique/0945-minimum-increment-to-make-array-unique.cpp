class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int count=0;
        sort(nums.begin(),nums.end());
        int i=0,j=1;
        while(j<nums.size())
        {
            while(nums[j]<=nums[i])
            {
                nums[j]+=1;
                count++;
            }
            i++;
            j++;
        }
        return count;
    }
};