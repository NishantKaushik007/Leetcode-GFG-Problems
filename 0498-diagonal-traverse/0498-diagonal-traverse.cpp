/* class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};

        int m = matrix.size(), n = matrix[0].size();
        vector<int> result(m * n);
        int row = 0, col = 0;

        for (int i = 0; i < m * n; i++) {
            result[i] = matrix[row][col];

            if ((row + col) % 2 == 0) {
                if (col == n - 1) row++;
                else if (row == 0) col++;
                else { row--; col++; }
            } else {
                if (row == m - 1) col++;
                else if (col == 0) row++;
                else { row++; col--; }
            }
        }

        return result;
    }
}; */






class Solution{
    public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat){
        int m = mat.size();
        int n = mat[0].size();

        map<int, vector<int>> mp;

        vector<int> result;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }

        bool flip = true;
        for(auto &it : mp){
            if(flip){
                reverse(it.second.begin(), it.second.end());
            }

            for(int &num : it.second){
                result.push_back(num);
            }

            flip = !flip;
        }

        return result;
    }
};