class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int>m;
        for(int i=0;i<trips.size();i++)
        {
            int start=trips[i][1];
            int end=trips[i][2];
            m[start]+=trips[i][0];
            m[end]-=trips[i][0];
        }
        int sum=0;
        for(auto it:m)
        {
            sum+=it.second;
            if(sum>capacity)
                return false;
        }
        return true;
    }
};