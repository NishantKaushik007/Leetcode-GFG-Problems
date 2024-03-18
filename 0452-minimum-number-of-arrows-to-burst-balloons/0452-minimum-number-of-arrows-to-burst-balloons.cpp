class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int count=1,endpoint=INT_MAX;
        sort(points.begin(),points.end());
        for(auto it:points)
        {
            int start=it[0];
            int end=it[1];
            //no overlapping
            if(endpoint<start)
            {
                count++;
                endpoint=end;
            }
            //overlapping
            else
            endpoint=min(endpoint,end);
        }
        return count;
    }
};