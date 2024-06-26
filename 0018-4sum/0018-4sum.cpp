class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(i>0&&nums[i]==nums[i-1])
                continue;
            for(int j=i+1;j<nums.size();j++)
            {
                if(j>i+1&&nums[j]==nums[j-1])
                    continue;
                int k=j+1,l=nums.size()-1;
                while(k<l)
                {
                    long long sum=nums[i];
                    sum+=nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    vector<int>v(4);
                    if(sum==target)
                    {
                        v[0]=nums[i];
                        v[1]=nums[j];
                        v[2]=nums[k];
                        v[3]=nums[l];
                        ans.push_back(v);
                        k++;
                        l--;
                        while(k<l&&nums[k]==nums[k-1])
                        k++;
                        while(k<l&&nums[l]==nums[l+1])
                        l--;
                    }
                    else if(sum<target)
                        k++;
                    else
                        l--;
                }
            }
        }
        return ans;
    }
};