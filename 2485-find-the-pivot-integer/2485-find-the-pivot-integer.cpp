class Solution {
public:
    int pivotInteger(int n) {
        int low=1,high=n;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if((mid*(mid+1)/2)==(((n*(n+1)/2)-(mid*(mid+1)/2))+mid))
                return mid;
            else if((mid*(mid+1)/2)<(((n*(n+1)/2)-(mid*(mid+1)/2))+mid))
                low=mid+1;
            else
                high=mid-1;
        }
        return -1;
    }
};