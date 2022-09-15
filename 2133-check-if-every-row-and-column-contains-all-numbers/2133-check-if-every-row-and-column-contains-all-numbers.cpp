class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
         for(int row=0;row<matrix.size();row++)
        {
            for(int col=0;col<matrix.size();col++)
            {
                if(matrix[row][col]!='.')
                {
                    int x=matrix[row][col];
                    matrix[row][col]=-1;
                    for(int i=0;i<matrix.size();i++)
                    {
                        if(matrix[row][i]==x)
                            return false;
                        if(matrix[i][col]==x)
                            return false;
                    }
                    matrix[row][col]=x;
                }
            }
        }
        return true;
    }
};