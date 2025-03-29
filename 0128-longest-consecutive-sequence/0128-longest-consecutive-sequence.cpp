class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longestSeq=0;
        unordered_set<int>s;
        for(int i=0;i<nums.size();i++)
        s.insert(nums[i]);
        for(int i=0;i<nums.size();i++)
        {
            int num=nums[i];
            if(s.count(num-1)==0)
            {
                int currSeq=0;
                while(s.count(num)==1)
                {
                    currSeq++;
                    num+=1;
                }
                longestSeq=max(longestSeq,currSeq);
            }
        }
        return longestSeq;
    }
};