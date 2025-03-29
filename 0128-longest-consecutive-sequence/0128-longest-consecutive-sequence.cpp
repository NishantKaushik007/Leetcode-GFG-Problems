class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longestSeq=0,currSeq=0;
        unordered_set<int>s;
        for(int i=0;i<nums.size();i++)
        s.insert(nums[i]);
        for(int i=0;i<nums.size();i++)
        {
            if(s.count(nums[i]-1)!=1)
            {
                int num=nums[i];
                currSeq=1;
                while(s.count(num+1)==1)
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