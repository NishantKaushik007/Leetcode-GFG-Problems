class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans;
        int i=0,j=0;
        while(i<nums.size()&&j<nums.size())
        {
            while(i<nums.size()&&nums[i]<0)
            i++;
            while(j<nums.size()&&nums[j]>=0)
            j++;
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
            i++;
            j++;
        }
        return ans;
    }
};