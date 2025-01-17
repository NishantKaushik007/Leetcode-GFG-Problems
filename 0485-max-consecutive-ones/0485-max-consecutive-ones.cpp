class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxOne=0,currOne=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                currOne++;
                maxOne=max(maxOne,currOne);
            }
            else{
                currOne=0;
            }
        }
        return maxOne;
    }
};