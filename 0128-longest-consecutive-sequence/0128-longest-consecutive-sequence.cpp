class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longestStreak=0,currStreak=0;
        unordered_set<int>st;
        for(int x:nums)
        st.insert(x);
        for(int i=0;i<nums.size();i++){
            if(st.count(nums[i]-1)!=1)
            {
                int num=nums[i];
                currStreak=1;
                while(st.count(num+1)==1){
                    currStreak++;
                    num=num+1;
                }
                longestStreak=max(longestStreak,currStreak);
            }
        }
        return longestStreak;
    }
};