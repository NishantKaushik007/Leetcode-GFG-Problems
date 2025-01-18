class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int>ahead(triangle.size(),-1);
        for(int i=0;i<triangle.size();i++)
        ahead[i]=triangle[triangle.size()-1][i];
        for(int i=triangle.size()-2;i>=0;i--)
        {
            vector<int>curr(triangle.size(),-1);
            for(int j=0;j<=i;j++)
            {
                int up=triangle[i][j]+ahead[j];
                int right=triangle[i][j]+ahead[j+1];
                curr[j]=min(up,right);
            }
            ahead=curr;
        }
        return ahead[0];
    }
};