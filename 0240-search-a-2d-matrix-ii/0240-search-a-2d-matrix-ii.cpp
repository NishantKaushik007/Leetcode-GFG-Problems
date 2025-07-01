class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ru=0,rd=matrix.size()-1,cl=0,cr=matrix[0].size()-1;
        while(ru<=rd&&cl<=cr)
        {
            if(matrix[ru][cr]==target)
            return true;
            else if(matrix[ru][cr]<target)
            ru++;
            else
            cr--;
        }
        return false;
    }
};