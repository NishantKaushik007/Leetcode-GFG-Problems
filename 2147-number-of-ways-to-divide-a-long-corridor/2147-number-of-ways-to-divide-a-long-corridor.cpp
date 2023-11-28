class Solution {
public:
    int mod=1e9+7;
    int numberOfWays(string corridor) {
        long long prod=1;
        vector<int>seatIndex;
        for(int i=0;i<corridor.length();i++)
        {
            if(corridor[i]=='S')
            {
                seatIndex.push_back(i);
            }
        }
        if(seatIndex.size()==0||seatIndex.size()%2!=0)
            return 0;
        int prev=seatIndex[1];
        for(int i=2;i<seatIndex.size();i+=2)
        {
            prod=(prod*(seatIndex[i]-seatIndex[i-1]))%mod;
            prev=seatIndex[i+1];
        }
        return prod;
    }
};