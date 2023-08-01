class Solution {
public:
    void solve(int start,int end,int k,vector<vector<int>>& res,vector<int>& v)
    {
        if(k==0)
        {
            res.push_back(v);
            return;
        }
        for(int i=start;i<=end;i++)
        {
            v.push_back(i);
            solve(i+1,end,k-1,res,v);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>res;
        vector<int>v;
        solve(1,n,k,res,v);
        return res;
    }
};