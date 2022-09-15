class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int row=0;row<n;row++)
        {
            unordered_set<int>s;
            for(int col=0;col<n;col++)
                s.insert(matrix[row][col]);
            for(int i=1;i<=n;i++)
                if(s.find(i)==s.end())
                    return false;
        }
        for(int row=0;row<n;row++)
        {
            unordered_set<int>s;
            for(int col=0;col<n;col++)
                s.insert(matrix[col][row]);
            for(int i=1;i<=n;i++)
                if(s.find(i)==s.end())
                    return false;
        }
        return true;
    }
};