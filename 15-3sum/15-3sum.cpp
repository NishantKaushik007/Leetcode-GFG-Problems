class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<nums.size()-2;i++)
        {
            if(i==0||(i>0)&&nums[i]!=nums[i-1])
            {
            int l=i+1,r=nums.size()-1,sum=0-nums[i];;
            while(l<r)
            {
                if(nums[l]+nums[r]==sum)
                {
                    vector<int>v;
                    v.push_back(nums[i]);
                    v.push_back(nums[l]);
                    v.push_back(nums[r]);
                    ans.push_back(v);
                    while(l<r&&nums[l]==nums[l+1])
                        l++;
                    while(l<r&&nums[r]==nums[r-1])
                        r--;
                    l++;
                    r--;
                }
                else if(nums[l]+nums[r]<sum)
                    l++;
                else
                    r--;
            }
            }
        }
        return ans;
    }
};