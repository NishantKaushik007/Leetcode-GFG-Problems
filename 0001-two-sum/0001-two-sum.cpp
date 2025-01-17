class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans(2,-1);
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            int num=nums[i];
            if(m.find(target-num)!=m.end())
            {
                ans[0]=m[target-num];
                ans[1]=i;
                break;
            }
            m[num]=i;
        }
        return ans;
    }
};