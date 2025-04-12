class Solution {
public:
    int upper_bound(int num,vector<int>& v,int n)
    {
        int low=0,high=n-1,ans=n;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(v[mid]<=num)
            low=mid+1;
            else
            {
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
    int countLeftSmall(int num,vector<vector<int>>& matrix,int n)
    {
        int count=0;
        for(int i=0;i<n;i++)
        {
            count+=upper_bound(num,matrix[i],n);
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int low=INT_MAX,high=INT_MIN,req=k-1,n=matrix.size();
        for(int i=0;i<n;i++)
        {
            low=min(low,matrix[i][0]);
            high=max(high,matrix[i][n-1]);
        }
        while(low<=high)
        {
            int mid=(low+high)/2;
            int leftSmall=countLeftSmall(mid,matrix,n);
            if(leftSmall<=req)
            low=mid+1;
            else
            high=mid-1;
        }
        return low;
    }
};