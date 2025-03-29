class Solution {
public:
    int merge(vector<int>& nums,int low,int mid,int high)
    {
        vector<int>v;
        int left=low,right=mid+1,count=0;
        while(left<=mid&&right<=high)
        {
            if(nums[left]>2ll*nums[right])
            {
                count+=(mid-left+1);
                right++;
            }
            else{
                left++;
            }
        }
        left=low,right=mid+1;
        while(left<=mid&&right<=high)
        {
            if(nums[left]>nums[right])
            {
                v.push_back(nums[right++]);
            }
            else{
                v.push_back(nums[left++]);
            }
        }
        while(left<=mid)
        v.push_back(nums[left++]);
        while(right<=high)
        v.push_back(nums[right++]);
        for(int i=low;i<=high;i++)
        nums[i]=v[i-low];
        return count;
    }
    int mergeSort(vector<int>& nums,int low,int high)
    {
        if(low>=high)
        return 0;
        int mid=(low+high)/2;
        int count=mergeSort(nums,low,mid);
        count+=mergeSort(nums,mid+1,high);
        count+=merge(nums,low,mid,high);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        return mergeSort(nums,low,high);
    }
};