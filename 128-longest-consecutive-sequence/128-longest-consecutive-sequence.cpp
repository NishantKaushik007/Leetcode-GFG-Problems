class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        int longestStreak=0,currentStreak=0;
        for(auto num:nums)
            s.insert(num);
        for(int i=0;i<nums.size();i++)
        {
            if(!s.count(nums[i]-1))
            {
                int num=nums[i];
                currentStreak=1;
                while(s.count(num+1))
                {
                    num+=1;
                    currentStreak++;
                }
            }
            longestStreak=max(longestStreak,currentStreak);
        }
        return longestStreak;
    }
};