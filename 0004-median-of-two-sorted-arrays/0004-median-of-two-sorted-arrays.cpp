class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        //wants to apply binary search on smaller array to reduce Time Complexity
        if(n1>n2)
            return findMedianSortedArrays(nums2,nums1);
        int low=0,high=n1;
        int left=(n1+n2+1)/2;   //elements required on left side
        int n=n1+n2;
        while(low<=high)
        {
            int mid1=(low+high)/2;  //(mid1)index of first on array1 on right
            //(mid2)index of first on array2 on right
            int mid2=left-mid1;       //getting remaining elements from 2nd array
        //l1 points to last element of 1st array, l2 points to last element of 2nd array on left 
            int l1=INT_MIN,l2=INT_MIN; //default values in case no elements taken
        //r1 points to 1st element of 1st array, r2 points to 1st element of 2nd array on right
            int r1=INT_MAX,r2=INT_MAX; //default values in case no elements taken
            if(mid1<n1)               //atleast 1 element on right side of array1
                r1=nums1[mid1];
            if(mid2<n2)               //atleast 1 element on right side of array2
                r2=nums2[mid2];
            if(mid1-1>=0)             //atleast 1 element on left side of array1
                l1=nums1[mid1-1];
            if(mid2-1>=0)            //atleast 1 element on left side of array2
                l2=nums2[mid2-1];
            if(l1<=r2&&l2<=r1)      //if all elements are at correct place
            {
                if(n%2==1)                   //odd elements in total
                    return max(l1,l2);
                else
                    return (double)(max(l1,l2)+min(r1,r2))/2.0;
            }
            else if(l1>r2)     //array1 element on left is greater than array2 element on right 
                high=mid1-1;        //reduce element of array1 because has extra element
            else if(l2>r1)     //array2 element on left is greater than array1 element on right
                low=mid1+1;     //add more element of array2 because has less element
        }
        return 0;
    }
};