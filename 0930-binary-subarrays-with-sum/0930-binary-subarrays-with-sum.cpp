class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>mp;
        int preSum=0,count=0;
        mp[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            preSum+=nums[i];
            int prevOcc=preSum-goal;
            if(mp.find(prevOcc)!=mp.end())
                count+=mp[prevOcc];
            mp[preSum]++;
        }
        return count;
    }
};