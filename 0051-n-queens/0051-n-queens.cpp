class Solution {
public:
    void placeQueen(int col,vector<string>& board,vector<vector<string>>& ans,int n,vector<int>& r,vector<int>& udia,vector<int>& ddia)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(r[i]==0&&udia[n-1+col-i]==0&&ddia[i+col]==0)
            {
                board[i][col]='Q';
                r[i]=1;
                udia[n-1+col-i]=1;
                ddia[i+col]=1;
                placeQueen(col+1,board,ans,n,r,udia,ddia);
                board[i][col]='.';
                r[i]=0;
                udia[n-1+col-i]=0;
                ddia[i+col]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        board[i]=s;
        vector<int>r(n,0);
        vector<int>udia(2*n-1,0);
        vector<int>ddia(2*n-1,0);
        placeQueen(0,board,ans,n,r,udia,ddia);
        return ans;
    }
};