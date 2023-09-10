class Solution {
public:
    int mod=1E9+7;
    int countOrders(int n) {
        if(n==1)
            return 1;
        long long res=1;
        for(int i=2;i<=n;i++)
        {
            int spaces=(i-1)*2+1;
            int curr_pos=spaces*(spaces+1)/2;
            res*=curr_pos;
            res%=mod;
        }
        return res;
    }
};