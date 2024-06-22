class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int unsatisfied=0,maxUnsatisfied=0,l=0,r=0,start=0;
        while(r<customers.size())
        {
            if(r-minutes>=0)
            {
                if(grumpy[r-minutes]==1)
                unsatisfied-=customers[r-minutes];
                l++;
            }
            if(grumpy[r]==1)
            {
                unsatisfied+=customers[r];
                if(unsatisfied>maxUnsatisfied)
                {
                    maxUnsatisfied=unsatisfied;
                    start=l;
                }
            }
            r++;
        }
        int satisfied=maxUnsatisfied;
        for(int i=0;i<customers.size();i++)
        {
            if(grumpy[i]==0)
            satisfied+=customers[i];
        }
        return satisfied;
    }
};