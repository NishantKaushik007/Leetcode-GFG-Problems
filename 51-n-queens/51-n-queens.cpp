class Solution {
public:
    
    void queen(int col,int n,vector<string>& board,vector<vector<string>>& ans,vector<int>& lowerDiagonal,vector<int>& upperDiagonal,vector<int>& leftRow)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(leftRow[row]==0&&lowerDiagonal[row+col]==0&&upperDiagonal[n-1+col-row]==0)
            {
                board[row][col]='Q';
                leftRow[row]=1;
                lowerDiagonal[row+col]=1;
                upperDiagonal[n-1+col-row]=1;
                queen(col+1,n,board,ans,lowerDiagonal,upperDiagonal,leftRow);
                board[row][col]='.';
                leftRow[row]=0;
                lowerDiagonal[row+col]=0;
                upperDiagonal[n-1+col-row]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
            board[i]=s;
        vector<int>lowerDiagonal(2*n-1,0);
        vector<int>upperDiagonal(2*n-1,0);
        vector<int>leftRow(n,0);
        queen(0,n,board,ans,lowerDiagonal,upperDiagonal,leftRow);
        return ans;
    }
};