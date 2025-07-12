class Solution {
public:
    bool possible(int day,vector<int>& bloomDay, int m, int k)
    {
        int bouquet=0;
        int flowers=0;
        for(int i=0;i<bloomDay.size();i++)
        {
            if(day>=bloomDay[i])
            {
                flowers++;
                if(flowers>=k)
                {
                    bouquet++;
                    flowers=0;
                }
            }
            else{
                flowers=0;
            }
        }
        if(bouquet>=m)
        return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=INT_MAX,high=INT_MIN,ans=-1;
        for(int num:bloomDay)
        {
            low=min(low,num);
            high=max(high,num);
        }
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(possible(mid,bloomDay,m,k))
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