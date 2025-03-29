class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            int num=nums[i];
            if(mp.find(target-num)!=mp.end())
            {
                ans.push_back(mp[target-num]);
                ans.push_back(i);
                break;
            }
            mp[num]=i;
        }
        return ans;
    }
};