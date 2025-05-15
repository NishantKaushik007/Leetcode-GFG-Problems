class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(i>0&&nums[i]==nums[i-1])
            continue;
            int low=i+1,high=nums.size()-1;
            while(low<high)
            {
                int sum=nums[i];
                sum+=nums[low];
                sum+=nums[high];
                if(sum==0)
                {
                    vector<int>v(3);
                    v[0]=nums[i];
                    v[1]=nums[low];
                    v[2]=nums[high];
                    ans.push_back(v);
                    low++;
                    high--;
                    while(low<high&&nums[low]==nums[low-1])
                    low++;
                    while(low<high&&nums[high]==nums[high+1])
                    high--;
                }
                else if(sum<0)
                low++;
                else
                high--;
            }
        }
        return ans;
    }
};