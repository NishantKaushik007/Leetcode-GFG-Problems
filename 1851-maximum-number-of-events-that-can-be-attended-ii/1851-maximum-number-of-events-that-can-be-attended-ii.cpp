class Solution {
public:
    int solve(int i,int k,vector<vector<int>>& events,vector<vector<int>>& dp)
    {
        if(i==events.size()||k==0)
        return 0;
        if(dp[i][k]!=-1)
        return dp[i][k];
        int notAttend=solve(i+1,k,events,dp);
        int attend=0;
        int j=i+1;
        for(;j<events.size();j++)
        {
            if(events[i][1]<events[j][0])
            break;
        }
        attend=events[i][2]+solve(j,k-1,events,dp);
        return dp[i][k]=max(notAttend,attend);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n=events.size();
        sort(events.begin(),events.end());
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return solve(0,k,events,dp);
    }
};