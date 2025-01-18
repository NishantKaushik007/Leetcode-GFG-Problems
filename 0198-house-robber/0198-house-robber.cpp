class Solution {
public:
    int rob(vector<int>& nums) {
        int prev=nums[0],prev2=0;
        for(int ind=1;ind<nums.size();ind++)
        {
            int notTake=prev;
            int take=nums[ind];
            if(ind>1)
            take+=prev2;
            int curr=max(take,notTake);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};