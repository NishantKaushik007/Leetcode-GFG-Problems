class Solution {
public:
    long long findOutHrs(int limit,vector<int>& piles)
    {
        long long hrs=0;
        for(int i=0;i<piles.size();i++)
        {
            hrs+=ceil(piles[i]/(double)limit);
        }
        return hrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=INT_MIN;
        for(int pile:piles)
        high=max(high,pile);
        while(low<=high)
        {
            int mid=(low+high)/2;
            long long hrs=findOutHrs(mid,piles);
            if(hrs<=h)
            {
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};