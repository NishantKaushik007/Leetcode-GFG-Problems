class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--)
        {
            int maxi=INT_MIN,ans=INT_MIN,len=0;
            for(int ind=i;ind<min(n,i+k);ind++)
            {
                len++;
                maxi=max(maxi,arr[ind]);
                int sum=(len*maxi)+dp[ind+1];
                ans=max(ans,sum);
            }
            dp[i]=ans;
        }
        return dp[0];
    }
};