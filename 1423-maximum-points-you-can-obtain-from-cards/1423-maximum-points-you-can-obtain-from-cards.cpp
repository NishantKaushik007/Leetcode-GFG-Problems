class Solution {
public:
    int solve(vector<int>& cardPoints, int k)
    {
        int maxSum=0,leftSum=0,rightSum=0;
        for(int i=0;i<k;i++)
        {
            leftSum+=cardPoints[i];
        }
        maxSum=leftSum;
        int r=cardPoints.size()-1;
        for(int i=k-1;i>=0;i--)
        {
            leftSum-=cardPoints[i];
            rightSum+=cardPoints[r];
            r--;
            maxSum=max(maxSum,leftSum+rightSum);
        }
        return maxSum;
    }
    int maxScore(vector<int>& cardPoints, int k) {
        return solve(cardPoints,k);
    }
};