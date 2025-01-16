class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int size=nums1.size()-1,size1=m-1,size2=n-1;
        while(size1>=0&&size2>=0){
            if(nums1[size1]<nums2[size2])
            nums1[size--]=nums2[size2--];
            else
            nums1[size--]=nums1[size1--];
        }
        while(size1>=0)
        nums1[size--]=nums1[size1--];
        while(size2>=0)
        nums1[size--]=nums2[size2--];
    }
};