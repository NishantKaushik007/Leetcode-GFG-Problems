class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        long long nn=n;
        if(nn<0)
        nn=-1*nn;
        while(nn)
        {
            if(nn&1)
            ans*=x;
            x*=x;
            nn=nn>>1;
        }
        if(n<0)
        return 1/ans;
        return ans;
    }
};