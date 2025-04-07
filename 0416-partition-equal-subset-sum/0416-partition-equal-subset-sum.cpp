class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int num:nums)
        sum+=num;
        if(sum%2==1)
        return false;
        vector<int>prev(sum/2+1,0);
        for(int i=0;i<nums.size();i++)
        prev[0]=1;
        if(nums[0]<=sum/2)
        prev[nums[0]]=1;
        for(int ind=1;ind<nums.size();ind++)
        {
            vector<int>curr(sum/2+1,0);
            for(int target=1;target<=sum/2;target++)
            {
                bool take=false;
                if(nums[ind]<=target)
                take=prev[target-nums[ind]];
                bool notTake=prev[target];
                curr[target]=take|notTake;
            }
            prev=curr;
        }
        return prev[sum/2];
    }
};