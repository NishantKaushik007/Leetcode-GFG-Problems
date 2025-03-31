class Solution {
public:
    int robbed(vector<int>& nums) {
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
    int rob(vector<int>& nums) {
        if(nums.size()==1)
        return nums[0];
        vector<int>num1(nums.begin(),nums.end()-1),num2(nums.begin()+1,nums.end());
        return max(robbed(num1),robbed(num2));
    }
};