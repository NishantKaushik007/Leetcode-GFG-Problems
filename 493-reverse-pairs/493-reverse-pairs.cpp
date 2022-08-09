class Solution {
public:
    int merge(vector<int> &nums,int low,int high,int mid)
    {
        int count=0,j=mid+1;
        for(int i=low;i<=mid;i++)
        {
            while(j<=high&&nums[i]>2LL*nums[j])
            {
                j++;
            }
            count+=(j-(mid+1));
        }
        vector<int>v;
        int left=low,right=mid+1;
        while(left<=mid&&right<=high)
        {
            if(nums[left]<=nums[right])
                v.push_back(nums[left++]);
            else
                v.push_back(nums[right++]);
        }
        while(left<=mid)
            v.push_back(nums[left++]);
        while(right<=high)
            v.push_back(nums[right++]);
        for(int i=low;i<=high;i++)
            nums[i]=v[i-low];
        return count;
    }
    int inverse(vector<int> &nums,int low,int high)
    {
        if(low>=high)
            return 0;
        int mid=(low+high)/2;
        int inv=inverse(nums,low,mid);
        inv+=inverse(nums,mid+1,high);
        inv+=merge(nums,low,high,mid);
        return inv;
    }
    int reversePairs(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        return inverse(nums,low,high);
    }
};