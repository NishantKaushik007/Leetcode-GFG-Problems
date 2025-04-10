class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int maxLen=1,lastInd=0,n=arr.size();
        vector<int>dp(n,1),parent(n),ans;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            for(int j=0;j<i;j++)
            {
                if(arr[i]%arr[j]==0&&dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                    parent[i]=j;
                }
            }
            if(maxLen<dp[i])
            {
                maxLen=dp[i];
                lastInd=i;
            }
        }
        ans.push_back(arr[lastInd]);
        while(parent[lastInd]!=lastInd)
        {
            lastInd=parent[lastInd];
            ans.push_back(arr[lastInd]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};