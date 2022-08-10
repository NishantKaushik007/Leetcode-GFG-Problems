class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        if(nums.size()==0)
            return ans;
        for(int i=0;i<nums.size();i++)
        {
            long long target3=target-nums[i];
            for(int j=i+1;j<nums.size();j++)
            {
                long long target2=target3-nums[j];
                    int front=j+1,back=nums.size()-1;
                while(front<back)
                {
                    int sum=nums[front]+nums[back];
                    if(sum<target2)
                        front++;
                    else if(sum>target2)
                        back--;
                    else
                    {
                        vector<int>v(4,0);
                        v[0]=nums[i];
                        v[1]=nums[j];
                        v[2]=nums[front];
                        v[3]=nums[back];
                        ans.push_back(v);
                        while(front<back&&nums[front]==v[2])
                        front++;
                        while(front<back&&nums[back]==v[3])
                        back--;
                    }
                }
                while(j+1<nums.size()&&nums[j+1]==nums[j])
                    j++;
            }
            while(i+1<nums.size()&&nums[i+1]==nums[i])
                    i++;
        }
        return ans;
    }
};