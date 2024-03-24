class Solution {
public:
    long long timeTaken(int hourly,vector<int>& piles)
    {
        long long totTime=0;
        for(int x:piles)
            totTime+=ceil(x/(double)hourly);
        return totTime;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int high=INT_MIN,low=1,ans=-1;
        for(int x:piles)
            if(x>high)
                high=x;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            long long totHours=timeTaken(mid,piles);
            if(totHours<=h)
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};