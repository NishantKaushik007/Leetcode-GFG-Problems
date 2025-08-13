class Solution {
public:
    bool isPowerOfThree(int n) {
        int low=0,high=n;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(pow(3,mid)==n)
            return true;
            else if(pow(3,mid)<n)
            low=mid+1;
            else
            high=mid-1;
        }
        return false;
    }
};