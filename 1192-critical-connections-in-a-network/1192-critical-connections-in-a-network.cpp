class Solution {
private:
    int timer=1;
    void dfs(int node,int parent,vector<int>& vis,vector<int>& tin,vector<int>& low,vector<vector<int>>& bridges,vector<int> adj[])
    {
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        for(auto it:adj[node])
        {
            if(it==parent)
                continue;
            if(!vis[it])
            {
                dfs(it,node,vis,tin,low,bridges,adj);
                low[node]=min(low[node],low[it]);
                if(low[it]>tin[node])
                    bridges.push_back({node,it});
            }
            else
            {
                low[node]=min(low[node],low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>tin(n,0),low(n,0),vis(n,0);
        vector<vector<int>>bridges;
        vector<int>adj[n];
        for(auto it:connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,-1,vis,tin,low,bridges,adj);
            }
        }
        return bridges;
    }
};