class Solution {
public:
    int solve(int i,vector<int>& arr,int k,int n,vector<int>& dp)
    {
        if(i==n)
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        int maxi=INT_MIN,ans=INT_MIN,len=0;
        for(int ind=i;ind<min(n,i+k);ind++)
        {
            len++;
            maxi=max(maxi,arr[ind]);
            int sum=(len*maxi)+solve(ind+1,arr,k,n,dp);
            ans=max(ans,sum);
        }
        return dp[i]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n,-1);
        return solve(0,arr,k,n,dp);
    }
};