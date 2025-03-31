class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<int>prev(matrix[0].size(),-1);
        for(int j=0;j<matrix[0].size();j++)
        prev[j]=matrix[0][j];
        for(int i=1;i<matrix.size();i++)
        {
            vector<int>curr(matrix[0].size(),-1);
            for(int j=0;j<matrix[0].size();j++)
            {
                int left=1e8;
                if(j-1>=0)
                left=matrix[i][j]+prev[j-1];
                int down=matrix[i][j]+prev[j];
                int right=1e8;
                if(j+1<matrix[0].size())
                right=matrix[i][j]+prev[j+1];
                curr[j]=min(left,min(down,right));
            }
            prev=curr;
        }
        int mini=1e8;
        for(int i=0;i<matrix[0].size();i++)
        mini=min(mini,prev[i]);
        return mini;
    }
};