class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //int duprow,dupcol;
        for(int row=0;row<9;row++)
        {
            for(int col=0;col<9;col++)
            {
                if(board[row][col]!='.')
                {
                    char c=board[row][col];
                    board[row][col]='.';
                    //duprow=row,dupcol=col;
                    for(int i=0;i<9;i++)
                    {
                        if(board[row][i]==c)
                            return false;
                        if(board[i][col]==c)
                            return false;
                        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)
                            return false;
                    }
                    board[row][col]=c;
                    //row=duprow,col=dupcol;
                }
            }
        }
        return true;
    }
};