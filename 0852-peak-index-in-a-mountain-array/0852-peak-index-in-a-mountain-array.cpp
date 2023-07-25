class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int high=arr.size()-1,low=0;
        while(low<=high)
        {
            int mid=(high+low)/2;
            if(arr[mid]>arr[mid+1]&&arr[mid]>arr[mid-1])
            return mid;
            else if(arr[mid]<arr[mid+1])
            low=mid+1;
            else
            high=mid-1;
        }
        return low;
    }
};