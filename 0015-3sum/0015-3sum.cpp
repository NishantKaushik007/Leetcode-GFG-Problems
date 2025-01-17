class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<nums.size();i++)
        {
            if(i>0&&nums[i]==nums[i-1])
            continue;
            int j=i+1,k=nums.size()-1;
            while(j<k){
                int sum=nums[i];
                sum+=nums[j];
                sum+=nums[k];
                vector<int>v(3);
                if(sum==0)
                {
                    v[0]=nums[i];
                    v[1]=nums[j];
                    v[2]=nums[k];
                    ans.push_back(v);
                    j++;
                    k--;
                    while(j<k&&nums[j]==nums[j-1])
                    j++;
                    while(j<k&&nums[k]==nums[k+1])
                    k--;
                }
                else if(sum<0)
                j++;
                else
                k--;
            }
        }
        return ans;
    }
};