class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxi=0;
        vector<int>left(nums.size()),right(nums.size());
        left[0]=nums[0],right[nums.size()-1]=nums[nums.size()-1];
        for(int i=1;i<nums.size();i++)
        {
            left[i]=max(left[i-1],nums[i]);
        }
        for(int i=nums.size()-2;i>=0;i--)
        {
            right[i]=max(right[i+1],nums[i]);
        }
        for(int i=1;i<nums.size()-1;i++)
        {
            long long t=(left[i-1]-nums[i])*1LL*right[i+1];
            maxi=max(maxi,t);
        }
        return maxi;
    }
};