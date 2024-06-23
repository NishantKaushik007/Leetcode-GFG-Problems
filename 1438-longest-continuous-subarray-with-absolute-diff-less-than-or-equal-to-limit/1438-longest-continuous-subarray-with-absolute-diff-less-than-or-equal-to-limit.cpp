class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int l=0,maxLen=0;
        multiset<int>window;
        for(int r=0;r<nums.size();r++)
        {
            window.insert(nums[r]);
            while(*window.rbegin()-*window.begin()>limit)
            {
                window.erase(window.find(nums[l]));
                l++;
            }
            maxLen=max(maxLen,r-l+1);
        }
        return maxLen;
    }
};