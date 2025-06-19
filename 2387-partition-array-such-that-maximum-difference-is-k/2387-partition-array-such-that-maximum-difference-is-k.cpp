class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int count=0,last=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]-last<=k)
            continue;
            else{
                last=nums[i];
                count++;
            }
        }
        return count+1;
    }
};