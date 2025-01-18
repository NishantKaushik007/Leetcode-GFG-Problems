class Solution {
public:
    int robbed(vector<int>& nums) {
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
    int rob(vector<int>& nums) {
        if(nums.size()==1)
        return nums[0];
        vector<int>v1(nums.begin(),nums.end()-1),v2(nums.begin()+1,nums.end());
        return max(robbed(v1),robbed(v2));
    }
};