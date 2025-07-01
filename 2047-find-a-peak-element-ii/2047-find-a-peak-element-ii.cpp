class Solution {
public:
    int findMax(vector<vector<int>>& mat,int col)
    {
        int maxi=INT_MIN,nrow=-1;
        for(int i=0;i<mat.size();i++)
        {
            if(maxi<mat[i][col])
            {
                maxi=mat[i][col];
                nrow=i;
            }
        }
        return nrow;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low=0,high=mat[0].size()-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int row=findMax(mat,mid);
            int left=mid-1>=0?mat[row][mid-1]:-1;
            int right=mid+1<mat[0].size()?mat[row][mid+1]:-1;
            if(mat[row][mid]>left&&mat[row][mid]>right)
            return {row,mid};
            else if(mat[row][mid]>left)
            low=mid+1;
            else
            high=mid-1;
        }
        return {-1,-1};
    }
};