class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size(),count=0;
        vector<vector<int>>mat(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        mat[i][0]=matrix[i][0];
        for(int i=0;i<m;i++)
        mat[0][i]=matrix[0][i];
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[i][j]==1)
                {
                    mat[i][j]=min(mat[i-1][j-1],min(mat[i-1][j],mat[i][j-1]))+1;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                count+=mat[i][j];
            }
        }
        return count;
    }
};