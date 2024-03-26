class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long nn=n;
        if(nn<0)
            nn*=-1;
        while(nn)
        {
            if(nn&1)
            ans*=x;
            x*=x;
            nn=nn>>1;
        }
        if(n<0)
            return (double)1.0/ans;
        return ans;
    }
};