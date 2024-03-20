class Solution {
public:
    int uniquePaths(int m, int n) {
        int x=m+n-2,r=m-1;
        double ans=1;
        for(int i=1;i<=r;i++)
        {
            ans=ans*(x-r+i)/i;
        }
        return ans;
    }
};