class Solution {
public:
    int countSetBits(int x)
    {
        int count=0;
        while(x!=0)
        {
            x=x&(x-1);
            count++;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int>ans(n+1,0);
        for(int i=0;i<=n;i++)
        {
            ans[i]=countSetBits(i);
        }
        return ans;
    }
};