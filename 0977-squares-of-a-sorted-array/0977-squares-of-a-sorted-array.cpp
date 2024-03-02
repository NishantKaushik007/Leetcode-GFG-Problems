class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>ans;
        int i=-1,j=-1;
        for(int x=0;x<nums.size();x++)
        {
            if(nums[x]<0)
                i++;
        }
        if(i<nums.size()-1&&i>-1)
        {
            j=i+1;
            while(i>=0&&j<nums.size())
            {
                if((-1*nums[i])>nums[j])
                {
                    ans.push_back(nums[j]*nums[j]);
                    j++;
                }
                else{
                    ans.push_back(nums[i]*nums[i]);
                    i--;
                }
            }
            while(i>=0)
            {
                ans.push_back(nums[i]*nums[i]);
                i--;
            }
            while(j<nums.size())
            {
                ans.push_back(nums[j]*nums[j]);
                j++;
            }
        }
        else if(i==-1)
        {
            j=i+1;
            while(j<nums.size())
            {
                ans.push_back(nums[j]*nums[j]);
                j++;
            }
        }
        else if(i==nums.size()-1)
        {
            while(i>=0)
            {
                ans.push_back(nums[i]*nums[i]);
                i--;
            }
        }
        return ans;
    }
};