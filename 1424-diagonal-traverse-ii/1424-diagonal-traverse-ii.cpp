class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int,vector<int>>groups;
        for(int i=nums.size()-1;i>=0;i--)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                int diagonal=i+j;
                groups[diagonal].push_back(nums[i][j]);
            }
        }
        vector<int>ans;
        int curr=0;
        while(groups.find(curr)!=groups.end())
        {
            for(int num:groups[curr])
                ans.push_back(num);
            curr++;
        }
        return ans;
    }
};