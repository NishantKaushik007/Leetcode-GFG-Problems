class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int maxLen=1;
        vector<pair<int,int>>prevSmall(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            prevSmall[i].first=nums[i];
            prevSmall[i].second=1;
        }
        for(int i=1;i<prevSmall.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(prevSmall[j].first<prevSmall[i].first)
                {
                    prevSmall[i].second=max(prevSmall[j].second+1,prevSmall[i].second);
                }
            }
            maxLen=max(maxLen,prevSmall[i].second);
        }
        return maxLen;
    }
};