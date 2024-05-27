class Solution {
public:
    int specialArray(vector<int>& nums) {
        for(int i=nums.size();i>=0;i--)
        {
            int count=0;
            for(int x:nums)
            {
                if(x>=i)
                {
                    count++;
                    if(count>i)
                        continue;
                }
            }
            if(count==i)
                return count;
        }
        return -1;
    }
};