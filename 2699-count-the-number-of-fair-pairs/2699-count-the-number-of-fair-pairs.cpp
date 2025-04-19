class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long count=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            //gives 1st element index not less than (lower-nums[i])
            int ind=lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i])-nums.begin();
            int x=ind-i-1;
            //gives the 1st element greater than (upper-nums[i])
            ind=upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i])-nums.begin();
            int y=ind-1-i;
            count+=(y-x);
        }
        return count;
    }
};