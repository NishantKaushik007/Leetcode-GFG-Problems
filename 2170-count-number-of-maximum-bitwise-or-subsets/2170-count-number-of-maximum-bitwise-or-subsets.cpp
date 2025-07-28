class Solution {
public:
    int countMaxOr(int i,int currOr,int maxOr,vector<int>& nums)
    {
        if(i==nums.size())
        {
            return currOr==maxOr?1:0; 
        }
        int take=0;
        take+=countMaxOr(i+1,currOr|nums[i],maxOr,nums);
        int notTake=countMaxOr(i+1,currOr,maxOr,nums);
        return take+notTake;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr=0;
        for(int num:nums)
            maxOr |= num;
        return countMaxOr(0,0,maxOr,nums);
    }
};