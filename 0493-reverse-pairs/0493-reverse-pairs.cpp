class Solution {
public:
    int merge(int low,int mid,int high,vector<int>& arr)
    {
        int count=0;
        int left=low,right=mid+1;
        while(left<=mid&&right<=high)
        {
            if(arr[left]>2LL*arr[right])
            {
                count+=mid-left+1;
                right++;
            }
            else{
                left++;
            }
        }
        left=low,right=mid+1;
        vector<int>v;
        while(left<=mid&&right<=high)
        {
            if(arr[left]>arr[right])
            {
                v.push_back(arr[right++]);
            }
            else{
                v.push_back(arr[left++]);
            }
        }
        while(left<=mid)
        {
            v.push_back(arr[left++]);
        }
        while(right<=high)
        {
            v.push_back(arr[right++]);
        }
        for(int i=low;i<=high;i++)
        arr[i]=v[i-low];
        return count;
    }
    int mergeSort(int low,int high,vector<int>& arr)
    {
        if(low>=high)
        return 0;
        int mid=(low+high)/2;
        int inv=mergeSort(low,mid,arr);
        inv+=mergeSort(mid+1,high,arr);
        inv+=merge(low,mid,high,arr);
        return inv;
    }
    int reversePairs(vector<int>& nums) {
        int count=0,low=0,high=nums.size()-1;
        return mergeSort(low,high,nums);
    }
};