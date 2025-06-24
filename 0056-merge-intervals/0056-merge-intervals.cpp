class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>v;
        v.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++)
        {
            if(v.back()[1]<intervals[i][0])
            v.push_back(intervals[i]);
            else{
                v.back()[0]=min(v.back()[0],intervals[i][0]);
                v.back()[1]=max(v.back()[1],intervals[i][1]);
            }
        }
        return v;
    }
};