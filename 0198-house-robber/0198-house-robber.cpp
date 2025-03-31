class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1=nums[0],prev2=0;
        for(int ind=1;ind<nums.size();ind++)
        {
            int take=nums[ind];
            if(ind>1)
            take+=prev2;
            int notTake=0+prev1;
            int curr=max(take,notTake);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};