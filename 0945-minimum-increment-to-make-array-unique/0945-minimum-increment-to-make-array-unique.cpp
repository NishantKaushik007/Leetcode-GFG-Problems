class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int maxVal=0,n=nums.size(),minMoves=0;
        for(int i=0;i<n;i++)
            maxVal=max(maxVal,nums[i]);
        vector<int>freq(n+maxVal+1,0);
        for(int x:nums)
            freq[x]++;
        for(int i=0;i<freq.size();i++)
        {
            if(freq[i]<=1)
                continue;
            int duplicates=freq[i]-1;
            freq[i+1]+=duplicates;
            freq[i]=1;
            minMoves+=duplicates;
        }
        return minMoves;
    }
};