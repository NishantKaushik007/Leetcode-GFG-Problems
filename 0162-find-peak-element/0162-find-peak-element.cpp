class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        if(nums[0]>nums[1])
            return 0;
        if(nums[nums.size()-1]>nums[nums.size()-2])
            return nums.size()-1;
        int low=1,high=nums.size()-2;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid-1]<nums[mid]&&nums[mid]>nums[mid+1])
                return mid;
            //mid is on increasing curve and not peak so peak will be on right
            else if(nums[mid-1]<nums[mid])
                low=mid+1;
            //mid is on decreasing curve and not peak so peak will be on left
            else
                high=mid-1;
        }
        return -1;
    }
};