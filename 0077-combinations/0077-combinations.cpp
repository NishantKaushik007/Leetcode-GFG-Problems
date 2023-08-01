class Solution {
public:
    void solve(int start,int end,int k,vector<vector<int>>& res,vector<int>& v)
    {
        if(k==0)
        {
            res.push_back(v);
            return;
        }
        if(start>end)
            return;
        v.push_back(start);
        solve(start+1,end,k-1,res,v);
        v.pop_back();
        solve(start+1,end,k,res,v);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>res;
        vector<int>v;
        solve(1,n,k,res,v);
        return res;
    }
};