class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        int longestStreak=0,currStreak=0;
        for(int x:nums)
            s.insert(x);
        for(int x:nums)
        {
            if(s.count(x-1)!=1)
            {
                int num=x;
                currStreak=1;
                while(s.count(num+1)==1)
                {
                    currStreak++;
                    num+=1;
                }
                longestStreak=max(currStreak,longestStreak);
            }
        }
        return longestStreak;
    }
};