class Solution {
public:
    void dfs(string& src,string& dst,unordered_map<string,vector<pair<string,double>>>& adj,unordered_set<string>& vis,double& ans,double product)
    {
        if(vis.find(src)!=vis.end())
        return;
        if(src==dst)
        {
            ans=product;
            return;
        }
        vis.insert(src);
        for(auto it:adj[src])
        {
            string v=it.first;
            double val=it.second;
            dfs(v,dst,adj,vis,ans,product*val);
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>>adj;
        for(int i=0;i<equations.size();i++)
        {
            string u=equations[i][0];
            string v=equations[i][1];
            double val=values[i];
            adj[u].push_back({v,val});
            adj[v].push_back({u,1.0/val});
        }
        vector<double>result;
        for(auto it:queries)
        {
            string src=it[0];
            string dst=it[1];
            double ans=-1.0;
            double product=1.0;
            unordered_set<string>vis;
            if(adj.find(src)!=adj.end())
            dfs(src,dst,adj,vis,ans,product);
            result.push_back(ans);
        }
        return result;
    }
};