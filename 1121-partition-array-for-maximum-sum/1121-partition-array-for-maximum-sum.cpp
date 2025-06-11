class Solution {
public:
    int maxSum(int i,vector<int>& arr,int k,int n,vector<int>& dp)
    {
        if(i==arr.size())
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        int len=0;
        int maxElement=INT_MIN;
        int maxi=INT_MIN;
        for(int ind=i;ind<min(n,i+k);ind++)
        {
            len++;
            maxElement=max(maxElement,arr[ind]);
            maxi=max(maxi,len*maxElement+maxSum(ind+1,arr,k,n,dp));
        }
        return dp[i]=maxi;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n,-1);
        return maxSum(0,arr,k,n,dp);
    }
};