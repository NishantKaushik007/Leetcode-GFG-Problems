class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rt=0,rb=matrix.size()-1,cl=0,cr=matrix[0].size()-1;
        while(rt<=rb&&cl<=cr)
        {
            if(matrix[rt][cr]==target)
                return true;
            else if(matrix[rt][cr]>target)
                cr--;
            else
                rt++;
        }
        return false;
    }
};