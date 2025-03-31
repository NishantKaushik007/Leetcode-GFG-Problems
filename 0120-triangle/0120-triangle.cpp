class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int>ahead(triangle.size(),0);
        for(int i=0;i<triangle.size();i++)
        ahead[i]=triangle[triangle.size()-1][i];
        for(int i=triangle.size()-2;i>=0;i--)
        {
            vector<int>curr(triangle.size(),0);
            for(int j=i;j>=0;j--)
            {
                int down=triangle[i][j]+ahead[j];
                int right=triangle[i][j]+ahead[j+1];
                curr[j]=min(down,right);
            }
            ahead=curr;
        }
        return ahead[0];
    }
};