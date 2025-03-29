class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<nums.size();i++)
        {
            if(i!=0&&nums[i]==nums[i-1])
            continue;
            for(int j=i+1;j<nums.size();j++)
            {
                if(j!=i+1&&nums[j]==nums[j-1])
                continue;
                int low=j+1,high=nums.size()-1;
                while(low<high)
                {
                    long long sum=nums[i];
                    sum+=nums[j];
                    sum+=nums[low];
                    sum+=nums[high];
                    if(sum==target)
                    {
                        vector<int>v(4);
                        v[0]=nums[i];
                        v[1]=nums[j];
                        v[2]=nums[low];
                        v[3]=nums[high];
                        ans.push_back(v);
                        low++;
                        high--;
                        while(low<high&&nums[low]==nums[low-1])
                        low++;
                        while(low<high&&nums[high]==nums[high+1])
                        high--;
                    }
                    else if(sum>target)
                    high--;
                    else
                    low++;
                }
            }
        }
        return ans;
    }
};