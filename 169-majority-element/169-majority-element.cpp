class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=1,res=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(res==nums[i])
                count++;
            if(res!=nums[i])
                count--;
            if(count==0)
            {
                res=nums[i];
                count=1;
            }
        }
        return res;
    }
};