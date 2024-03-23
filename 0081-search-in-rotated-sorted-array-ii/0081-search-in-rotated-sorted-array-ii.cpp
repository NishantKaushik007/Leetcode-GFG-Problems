class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==target)
                return true;
            //both low and high are same and not the target, so trim the array
            else if(nums[low]==nums[mid]&&nums[mid]==nums[high])
            {
                low++;
                high--;
            }
            //is left sorted
            else if(nums[low]<=nums[mid])
            {
                if(nums[low]<=target&&target<=nums[mid])
                {
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            //is right sorted
            else{
                if(nums[high]>=target&&nums[mid]<=target)
                {
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return false;
    }
};