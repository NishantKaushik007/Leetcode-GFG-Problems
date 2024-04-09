class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>>ans;
        ans=matrix;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    //col
                    for(int k=0;k<matrix[0].size();k++)
                        ans[i][k]=0;
                    //row
                    for(int k=0;k<matrix.size();k++)
                        ans[k][j]=0;
                }
            }
        }
        matrix=ans;
    }
};