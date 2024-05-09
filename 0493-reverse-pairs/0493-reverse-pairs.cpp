class Solution {
public:
    void merge(int low,int mid,int high,vector<int>& nums,int& count)
    {
        vector<int>v;
        int left=low,right=mid+1;
        while(left<=mid&&right<=high)
        {
            if(nums[left]>2LL*nums[right])
            {
                count+=mid-left+1;
                right++;
            }
            else{
                left++;
            }
        }
        left=low,right=mid+1;
        while(left<=mid&&right<=high)
        {
            if(nums[left]<=nums[right])
            {
                v.push_back(nums[left++]);
            }
            else{
                v.push_back(nums[right++]);
            }
        }
        while(left<=mid)
            v.push_back(nums[left++]);
        while(right<=high)
            v.push_back(nums[right++]);
        for(int i=low;i<=high;i++)
            nums[i]=v[i-low];
    }
    void mergeSort(int low,int high,vector<int>& nums,int& count)
    {
        if(low>=high)
            return;
        int mid=(low+high)/2;
        mergeSort(low,mid,nums,count);
        mergeSort(mid+1,high,nums,count);
        merge(low,mid,high,nums,count);
    }
    int reversePairs(vector<int>& nums) {
        int low=0,high=nums.size()-1,count=0;
        mergeSort(low,high,nums,count);
        return count;
    }
};