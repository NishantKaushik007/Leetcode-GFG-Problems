class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int s=0,e=nums.size()-1,n=nums.size();
        vector<int>ans(n,0);
        for(int i=n-1;i>=0;i--)
        {
            if(nums[s]*nums[s]>nums[e]*nums[e])
            {
                ans[i]=nums[s]*nums[s];
                s++;
            }
            else{
                ans[i]=nums[e]*nums[e];
                e--;
            }
        }
        return ans;
    }
};