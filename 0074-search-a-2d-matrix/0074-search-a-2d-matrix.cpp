class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rs=0,re=matrix.size()-1,cs=0,ce=matrix[0].size()-1;
        while(rs<=re&&cs<=ce)
        {
            if(matrix[rs][ce]==target)
                return true;
            if(matrix[rs][ce]>target)
                ce--;
            else
                rs++;
        }
        return false;
    }
};