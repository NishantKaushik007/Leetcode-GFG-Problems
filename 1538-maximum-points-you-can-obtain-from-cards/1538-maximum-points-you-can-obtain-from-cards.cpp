class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftPoints=0,rightPoints=0,maxPoints=0;
        for(int i=0;i<k;i++)
        leftPoints+=cardPoints[i];
        maxPoints=leftPoints;
        int left=k-1,right=cardPoints.size()-1;
        for(int i=left;i>=0;i--)
        {
            leftPoints-=cardPoints[i];
            rightPoints+=cardPoints[right--];
            maxPoints=max(maxPoints,leftPoints+rightPoints);
        }
        return maxPoints;
    }
};