class Solution {
public:
    bool isSafe(int row,int col,int n,vector<string>& board)
    {
        for(int i=col;i>=0;i--)
            if(board[row][i]=='Q')
                return false;
        int r=row,c=col;
        while(r>=0&&c>=0)
        {
            if(board[r][c]=='Q')
                return false;
            r--;
            c--;
        }
        r=row,c=col;
        while(r<n&&c>=0)
        {
            if(board[r][c]=='Q')
                return false;
            r++;
            c--;
        }
        return true;
    }
    void placeQueen(int col,int n,vector<string>& board,vector<vector<string>>& ans)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(isSafe(row,col,n,board))
            {
                board[row][col]='Q';
                placeQueen(col+1,n,board,ans);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
            board[i]=s;
        placeQueen(0,n,board,ans);
        return ans;
    }
};