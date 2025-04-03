class Solution {
public:
    bool isSafe(int row,int col,vector<string>& board,int n)
    {
        for(int i=col;i>=0;i--)
        {
            if(board[row][i]=='Q')
            return false;
        }
        int nrow=row-1,ncol=col-1;
        while(nrow>=0&&ncol>=0)
        {
            if(board[nrow][ncol]=='Q')
            return false;
            nrow--;
            ncol--;
        }
        nrow=row+1,ncol=col-1;
        while(nrow<n&&ncol>=0)
        {
            if(board[nrow][ncol]=='Q')
            return false;
            nrow++;
            ncol--;
        }
        return true;
    }
    void placeQueen(int col,vector<string>& board,vector<vector<string>>& ans,int n)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(isSafe(i,col,board,n))
            {
                board[i][col]='Q';
                placeQueen(col+1,board,ans,n);
                board[i][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        board[i]=s;
        placeQueen(0,board,ans,n);
        return ans;
    }
};