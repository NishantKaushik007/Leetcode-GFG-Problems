class Solution {
public:
    int solve(int i,int j,vector<int>& cuts,vector<vector<int>>& dp)
    {
        if(i>j)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int mini=INT_MAX;
        for(int ind=i;ind<=j;ind++)
        {
            mini=min(mini,(cuts[j+1]-cuts[i-1])+solve(i,ind-1,cuts,dp)+solve(ind+1,j,cuts,dp));
        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int sz=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(sz+2,vector<int>(sz+2,0));
        for(int i=sz;i>=1;i--)
        {
            for(int j=1;j<=sz;j++)
            {
                if(i>j)
                continue;
                int mini=INT_MAX;
                for(int ind=i;ind<=j;ind++)
                {
                    mini=min(mini,(cuts[j+1]-cuts[i-1])+dp[i][ind-1]+dp[ind+1][j]);
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][sz];
    }
};