class Solution {
public:
    double myPow(double x, int n) {
        long long nn=n;
        double ans=1;
        if(nn<0)
        nn=-1*nn;
        while(nn){
            if(nn&1)
            ans*=x;
            x=x*x;
            nn=nn>>1;
        }
        if(n<0)
        return double(1)/ans;
        return ans;
    }
};