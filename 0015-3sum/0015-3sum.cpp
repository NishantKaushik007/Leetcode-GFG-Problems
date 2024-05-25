class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(i!=0&&nums[i]==nums[i-1])
                continue;
            int l=i+1,h=nums.size()-1;
            while(l<h)
            {
                int sum=nums[i];
                sum+=nums[l];
                sum+=nums[h];
                if(sum==0)
                {
                    vector<int>v={nums[i],nums[l],nums[h]};
                    ans.push_back(v);
                    l++;
                    h--;
                    while(l<h&&nums[l]==nums[l-1])
                        l++;
                    while(l<h&&nums[h]==nums[h+1])
                        h--;
                }
                else if(sum>0)
                    h--;
                else
                    l++;
            }
        }
        return ans;
    }
};