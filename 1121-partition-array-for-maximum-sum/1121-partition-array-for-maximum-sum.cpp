class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--)
        {
            int len=0;
            int maxElement=INT_MIN;
            int maxi=INT_MIN;
            for(int ind=i;ind<min(n,i+k);ind++)
            {
                len++;
                maxElement=max(maxElement,arr[ind]);
                maxi=max(maxi,len*maxElement+dp[ind+1]);
            }
            dp[i]=maxi;
        }
        return dp[0];
    }
};