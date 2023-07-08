//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs(int row,int col,int n, int m, vector<vector<char>>& mat,vector<vector<int>>& vis,int drow[],int dcol[])
    {
        vis[row][col]=1;
        for(int i=0;i<4;i++)
        {
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&mat[nrow][ncol]=='O'&&!vis[nrow][ncol])
            {
                dfs(nrow,ncol,n,m,mat,vis,drow,dcol);
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>>vis(n,vector<int>(m,0));
        int drow[]={0,1,0,-1};
        int dcol[]={1,0,-1,0};
        for(int i=0;i<n;i++)
        {
            if(mat[i][0]=='O'&&!vis[i][0])
            {
                dfs(i,0,n,m,mat,vis,drow,dcol);
            }
            if(mat[i][m-1]=='O'&&!vis[i][m-1])
            {
                dfs(i,m-1,n,m,mat,vis,drow,dcol);
            }
        }
        for(int j=0;j<m;j++)
        {
            if(mat[0][j]=='O'&&!vis[0][j])
            {
                dfs(0,j,n,m,mat,vis,drow,dcol);
            }
            if(mat[n-1][j]=='O'&&!vis[n-1][j])
            {
                dfs(n-1,j,n,m,mat,vis,drow,dcol);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j]&&mat[i][j]=='O')
                mat[i][j]='X';
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends