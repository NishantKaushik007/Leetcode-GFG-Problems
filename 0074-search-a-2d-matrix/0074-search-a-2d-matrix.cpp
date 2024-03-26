class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rs=0,cs=0,re=matrix.size()-1,ce=matrix[0].size()-1;
        while(cs<=ce&&rs<=re)
        {
            if(matrix[rs][ce]==target)
                return true;
            else if(matrix[rs][ce]<target)
                rs++;
            else
                ce--;
        }
        return false;
    }
};