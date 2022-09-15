class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int row=0;row<n;row++)
        {
            vector<bool>rvis(n+1,false);
            vector<bool>cvis(n+1,false);
            for(int col=0;col<n;col++)
            {
                int r=matrix[row][col];
                int c=matrix[col][row];
                if(rvis[r]==true||cvis[c]==true)
                    return false;
                rvis[r]=true;
                cvis[c]=true;
            }
        }
        return true;
    }
};