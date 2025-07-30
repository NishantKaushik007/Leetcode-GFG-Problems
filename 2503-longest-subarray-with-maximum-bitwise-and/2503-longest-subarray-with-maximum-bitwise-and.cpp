class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal=0,streak=0,ans=0;
        for(int num:nums)
        {
            if(maxVal<num)
            {
                maxVal=num;
                ans=streak=0;
            }
            if(maxVal==num)
                streak++;
            else
                streak=0;
            ans=max(ans,streak);
        }
        return ans;
    }
};