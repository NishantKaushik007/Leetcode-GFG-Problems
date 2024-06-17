class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int left=0,right=0,maxPoints=0;
        for(int i=0;i<k;i++)
            left+=cardPoints[i];
        maxPoints=left;
        int j=cardPoints.size()-1;
        for(int i=k-1;i>=0;i--)
        {
            left-=cardPoints[i];
            right+=cardPoints[j];
            maxPoints=max(maxPoints,left+right);
            j--;
        }
        return maxPoints;
    }
};