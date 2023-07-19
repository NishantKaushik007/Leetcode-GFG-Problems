class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int count=0,i=0,j=1;
        while(j<intervals.size())
        {
            int cs=intervals[i][0];
            int ce=intervals[i][1];
            int ns=intervals[j][0];
            int ne=intervals[j][1];
            if(ce<=ns)
            {
                i=j;
                j++;
            }
            else if(ce<=ne)
            {
                count++;
                j++;
            }
            else if(ce>ne)
            {
                count++;
                i=j;
                j++;
            }
        }
        return count;
    }
};