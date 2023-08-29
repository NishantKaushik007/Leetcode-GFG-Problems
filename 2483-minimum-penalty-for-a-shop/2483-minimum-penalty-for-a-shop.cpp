class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size(),countN=0,countY=0;
        int minPenalty=INT_MAX,minHour=INT_MAX;
        vector<int>prefixN(n+1,0),suffixY(n+1,0);
        for(int i=1;i<=n;i++)
        {
            if(customers[i-1]=='N')
            {
                countN++;
            }
            prefixN[i]=countN;
            if(customers[n-i]=='Y')
            {
                countY++;
            }
            suffixY[n-i]=countY;
        }
        for(int i=0;i<=n;i++)
        {
            int penalty=prefixN[i]+suffixY[i];
            if(penalty<minPenalty)
            {
                minPenalty=penalty;
                minHour=i;
            }
        }
        return minHour;
    }
};