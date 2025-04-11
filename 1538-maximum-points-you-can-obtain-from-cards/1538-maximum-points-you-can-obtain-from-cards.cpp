class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftSum=0,rightSum=0,maxSum=0;
        for(int i=0;i<k;i++)
        leftSum+=cardPoints[i];
        maxSum=leftSum;
        int rightInd=cardPoints.size()-1;
        for(int i=k-1;i>=0;i--)
        {
            leftSum-=cardPoints[i];
            rightSum+=cardPoints[rightInd];
            maxSum=max(maxSum,leftSum+rightSum);
            rightInd--;
        }
        return maxSum;
    }
};