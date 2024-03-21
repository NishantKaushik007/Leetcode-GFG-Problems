class Solution {
public:
    int robs(vector<int>& nums) {
        int n=nums.size();
        int prev=nums[0],prev2=0;
        for(int i=1;i<n;i++)
        {
            int notTake=0+prev;
            int take=nums[i];
            if(i>1)
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
        vector<int>nums1(nums.begin(),nums.end()-1),nums2(nums.begin()+1,nums.end());
        return max(robs(nums1),robs(nums2));
    }
};