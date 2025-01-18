class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int num:nums)
        sum+=num;
        if(sum%2)
        return false;
        vector<bool>prev((sum/2)+1,false);
        for(int i=0;i<nums.size();i++)
        prev[0]=true;
        for(int ind=1;ind<nums.size();ind++)
        {
            vector<bool>curr((sum/2)+1,false);
            for(int tar=0;tar<=sum/2;tar++)
            {
                bool notTake=prev[tar];
                bool take=false;
                if(tar>=nums[ind])
                take=prev[tar-nums[ind]];
                curr[tar]=take|notTake;
            }
            prev=curr;
        }
        return prev[sum/2];
    }
};