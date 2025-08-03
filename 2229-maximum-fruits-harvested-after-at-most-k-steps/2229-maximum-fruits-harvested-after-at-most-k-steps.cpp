class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n=fruits.size(),maxFruits=0;
        vector<int>preSum(n),positions(n);
        for(int i=0;i<n;i++)
        {
            positions[i]=fruits[i][0];
            preSum[i]=fruits[i][1]+(i>0?preSum[i-1]:0);
        }
        for(int d=0;d<=k/2;d++)
        {
            int remaining=k-2*d;
            int i=startPos-d;
            int j=startPos+remaining;
            int left=lower_bound(positions.begin(),positions.end(),i)-positions.begin();
            int right=upper_bound(positions.begin(),positions.end(),j)-positions.begin()-1;
            if(left<=right)
            {
                int total=preSum[right]-(left>0?preSum[left-1]:0);
                maxFruits=max(maxFruits,total);
            }
            i=startPos-remaining;
            j=startPos+d;
            left=lower_bound(positions.begin(),positions.end(),i)-positions.begin();
            right=upper_bound(positions.begin(),positions.end(),j)-positions.begin()-1;
            if(left<=right)
            {
                int total=preSum[right]-(left>0?preSum[left-1]:0);
                maxFruits=max(maxFruits,total);
            }
        }
        return maxFruits;
    }
};