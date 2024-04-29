class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int res=k;
        for(int i=0;i<nums.size();i++)
        {
            res^=nums[i];
        }
        int count=0;
        while(res)
        {
            res=res&(res-1);
            count++;
        }
        return count;
    }
};